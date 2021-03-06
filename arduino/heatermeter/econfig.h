#ifndef __ECONFIG_H__
#define __ECONFIG_H__

/*
  Replacements for eeprom_read_block and eeprom_write_block which take less
  code size. They take less space to re-implement because avr-libc is built
  with prologue/epilogue so avoid including that for such a small function.
*/
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void econfig_read_block(void *_dst, const void *_src, uint8_t n);
uint16_t econfig_read_word(const void *_src);

void econfig_write_block(const void *_src, void *_dst, uint8_t  n);
void econfig_write_word(void *_dst, uint16_t val);
void econfig_write_byte(void *_dst, uint8_t val);

#ifdef __cplusplus
} // extern "C"
#endif

#endif