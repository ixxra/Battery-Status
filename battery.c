#include <stdio.h>


const char*  ENERGY_NOW = "/sys/class/power_supply/BAT0/energy_now";
const char* ENERGY_FULL = "/sys/class/power_supply/BAT0/energy_full";
const char*      STATUS = "/sys/class/power_supply/BAT0/status";

int main()
{
  int energy_now;
  int energy_full;
  char status[16];
  
  FILE* f = fopen(ENERGY_NOW, "r");
  fscanf(f, "%d", &energy_now);
  fclose(f);
  
  
  f = fopen(ENERGY_FULL, "r");
  fscanf(f, "%d", &energy_full);
  fclose(f);
  
  f = fopen(STATUS, "r");
  fscanf(f, "%s", status);
  fclose(f);
  
  float cap = (float) energy_now / (float) energy_full * 100;
  
  printf("Battery at %.0f%% (%s)\n", cap, status);
  
  return 0;
}