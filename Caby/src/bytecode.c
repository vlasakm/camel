#include "bytecode.h"
#include "common.h"

#include <string.h>

void init_bc_chunk(struct bc_chunk* c) {
    c->data = NULL;
    c->len = 0;
    c->cap = 0;
}

void free_bc_chunk(struct bc_chunk* c) {
    free(c->data);
    init_bc_chunk(c);
}

void write_byte(struct bc_chunk* c, u8 byte) {
    c->data = handle_capacity(c->data, c->len, &c->cap);
    c->data[c->len++] = byte;
}

void init_constant_pool(struct constant_pool* cp) {
    memset(cp, 0, sizeof(*cp));
}

void free_constant_pool(struct constant_pool* cp) {
    vfree(cp->data);
    init_constant_pool(cp);
}

void write_constant_pool(struct constant_pool* cp, struct object* object) {
    cp->cap = handle_capacity(cp->data, cp->len, cp->cap);
    cp->data[cp->len++] = object;

}
