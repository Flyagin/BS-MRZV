/***************
MCK = 132800000 √ц
PIT працюЇ з частотою MCK/16 = 8300000 √ц
ƒл€ 10мс треба 83000 такти таймера PIT
***************/
#define PIT_PERIOD 83000

enum __command_menu_bit__
{
  REWRITE_MENU = 0,
  REFRESH_ACTIVE_PANELS
};
