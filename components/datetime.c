/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <time.h>

#include "../slstatus.h"
#include "../util.h"

const char *
datetime(const char *fmt)
{
	time_t t;

	t = time(NULL);
	if (!strftime(buf, sizeof(buf), fmt, localtime(&t))) {
		warn("strftime: Result string exceeds buffer size");
		return NULL;
	}

	return buf;
}

const char *days_cn[] = {
    "周日",
    "周一",
    "周二",
    "周三",
    "周四",
    "周五",
    "周六"
};

const char *
day_cn(const char *fmt)
{
	time_t t = time(NULL);
    int weekday = localtime(&t)->tm_wday;

	return (weekday < (int)sizeof(days_cn) / (int)sizeof(char *)) ? days_cn[weekday] : "?";
}
