#include <stdio.h>

void main(){
	print_jiahao();
}

void print_jiahao(){
	print("this is just a test .c \n");
}

static void check_sanity_work(struct work_struct *work)
{
	struct fg_chip *chip = container_of(work,
				struct fg_chip,
				check_sanity_work.work);
	int rc = 0;
	u8 beat_count;
	bool tried_once = false;

	fg_stay_awake(&chip->sanity_wakeup_source);

try_again:
	rc = fg_read(chip, &beat_count,
			chip->mem_base + MEM_INTF_FG_BEAT_COUNT, 1);
	if (rc) {
		pr_err("failed to read beat count rc=%d\n", rc);
		goto resched;
	}

	if (fg_debug_mask & FG_STATUS)
		pr_info("current: %d, prev: %d\n", beat_count,
			chip->last_beat_count);

	if (chip->last_beat_count == beat_count) {
		if (!tried_once) {
			/* Wait for 1 FG cycle and read it once again */
			msleep(1500);
			tried_once = true;
			goto try_again;
		} else {
			pr_err("Beat count not updating\n");
			fg_check_ima_error_handling(chip);
			goto out;
		}
	} else {
		chip->last_beat_count = beat_count;
	}
resched:
	schedule_delayed_work(
		&chip->check_sanity_work,
		msecs_to_jiffies(SANITY_CHECK_PERIOD_MS));
out:
	fg_relax(&chip->sanity_wakeup_source);
}
