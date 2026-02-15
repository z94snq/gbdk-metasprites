#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdint.h>
#include <gb/metasprites.h>

#include "graphics/Oak.h"

void main(void)
{
    SHOW_SPRITES;

    // Not related to metasprites
    // This adjusts the DMG color palette so OAK has the proper colors
    OBP0_REG=DMG_PALETTE(DMG_LITE_GRAY, DMG_WHITE, DMG_DARK_GRAY, DMG_BLACK);

    set_sprite_data(0, 4, Oak_tiles);

    uint8_t startingSprite = 0;

    // Using "startingSprite" the first time isn't neccessary, but i like the consistency
    startingSprite+=move_metasprite_ex(Oak_metasprites[0], 0, 0, startingSprite, 80, 80);
    startingSprite+=move_metasprite_ex(Oak_metasprites[0], 0, 0, startingSprite, 20, 40);
    startingSprite+=move_metasprite_ex(Oak_metasprites[0], 0, 0, startingSprite, 30, 60);

    // Hide any remainder sprites
    hide_sprites_range(startingSprite, MAX_HARDWARE_SPRITES);

    // Loop forever
    while(1) {

		// Done processing, yield CPU and wait for start of next frame
        wait_vbl_done();
    }
}