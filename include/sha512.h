#ifndef SHA512_H
#define SHA512_H

#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint64_t u64;
#define u64hilo(hi, lo) ((u64) (((u64) (hi) << 32) + (lo)))
#define u64init(hi, lo) u64hilo (hi, lo)
#define u64lo(x) ((u64) (x))
#define u64size(x) u64lo (x)
#define u64lt(x, y) ((x) < (y))
#define u64and(x, y) ((x) & (y))
#define u64or(x, y) ((x) | (y))
#define u64xor(x, y) ((x) ^ (y))
#define u64plus(x, y) ((x) + (y))
#define u64shl(x, n) ((x) << (n))
#define u64shr(x, n) ((x) >> (n))

#define u64rol(x, n) u64or (u64shl (x, n), u64shr (x, 64 - n))

#define SHA384_DIGEST_SIZE  384 / 8
#define SHA512_DIGEST_SIZE  512 / 8

struct sha512_ctx
{
	u64 state[8];

	u64 total[2];
	size_t buflen;  /* ≥ 0, ≤ 256 */
	u64 buffer[32]; /* 256 bytes; */
};

extern void sha512_init_ctx(struct sha512_ctx* ctx);
extern void sha384_init_ctx(struct sha512_ctx* ctx);

extern void sha512_process_block(const void* buffer, size_t len, struct sha512_ctx* ctx);
extern void sha512_process_bytes(const void* buffer, size_t len, struct sha512_ctx* ctx);

extern void* sha512_finish_ctx(struct sha512_ctx* ctx, void* resbuf);
extern void* sha384_finish_ctx(struct sha512_ctx* ctx, void* resbuf);

extern void* sha512_read_ctx(const struct sha512_ctx* ctx, void* resbuf);
extern void* sha384_read_ctx(const struct sha512_ctx* ctx, void* resbuf);

extern void* sha512_buffer(const char* buffer, size_t len, void* resblock);
extern void* sha384_buffer(const char* buffer, size_t len, void* resblock);

extern int sha512_stream(FILE* stream, void* resblock);
extern int sha384_stream(FILE* stream, void* resblock);

#ifdef __cplusplus
}
#endif

#endif /* SHA512_H */