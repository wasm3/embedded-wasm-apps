
#ifndef WASM_RT_HELPERS_H_
#define WASM_RT_HELPERS_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "wasm-app.h"

typedef u32 wasm_ptr;

#define IMPORT_IMPL(name, ret, params, body)            \
  static ret _##name params body                        \
  ret (*WASM_RT_ADD_PREFIX(name)) params = _##name;

#define IMPORT_IMPL_PARTICLE(name, ret, params, body)   \
  IMPORT_IMPL(Z_particle##name, ret,  params, body)

#define IMPORT_IMPL_WIRING(name, ret, params, body)   \
  IMPORT_IMPL(Z_wiring##name, ret,  params, body)

#define MEMACCESS(addr) ((void*)&WASM_RT_ADD_PREFIX(Z_memory)->data[(addr)])

#define MEM_SET(addr, value, len) memset(MEMACCESS(addr), value, len)
#define MEM_WRITE8(addr, value)  (*(u8*) MEMACCESS(addr)) = value
#define MEM_WRITE16(addr, value) (*(u16*)MEMACCESS(addr)) = value
#define MEM_WRITE32(addr, value) (*(u32*)MEMACCESS(addr)) = value
#define MEM_WRITE64(addr, value) (*(u64*)MEMACCESS(addr)) = value

#define MEM_READ32(addr) (*(u32*)MEMACCESS(addr))


#endif /* WASM_RT_HELPERS_H_ */
