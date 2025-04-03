#include <pico/stdlib.h>
#include "pico/rand.h"
#include "hardware/gpio.h"

const uint MASK = 0b111;

int main(){

	gpio_init_mask(MASK);
	gpio_set_dir_masked(MASK, MASK); // (0b111, 0b111);
	while(1){
		uint32_t r_num = get_rand_32() % 3;

		gpio_put(r_num, 1);
        	sleep_ms(50);
		for(int i = 0; i < 3; i++){
			gpio_put(i, 0);
		}
	}
	return 0;
}
