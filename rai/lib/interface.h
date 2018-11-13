#ifndef BCB_INTERFACE_H
#define BCB_INTERFACE_H

#if __cplusplus
extern "C" {
#endif

typedef unsigned char * bcb_uint128; // 16byte array for public and private keys
typedef unsigned char * bcb_uint256; // 32byte array for public and private keys
typedef unsigned char * bcb_uint512; // 64byte array for signatures
typedef void * bcb_transaction;

// Convert amount bytes 'source' to a 39 byte not-null-terminated decimal string 'destination'
void bcb_uint128_to_dec (const bcb_uint128 source, char * destination);
// Convert public/private key bytes 'source' to a 64 byte not-null-terminated hex string 'destination'
void bcb_uint256_to_string (const bcb_uint256 source, char * destination);
// Convert public key bytes 'source' to a 65 byte non-null-terminated account string 'destination'
void bcb_uint256_to_address (bcb_uint256 source, char * destination);
// Convert public/private key bytes 'source' to a 128 byte not-null-terminated hex string 'destination'
void bcb_uint512_to_string (const bcb_uint512 source, char * destination);

// Convert 39 byte decimal string 'source' to a byte array 'destination'
// Return 0 on success, nonzero on error
int bcb_uint128_from_dec (const char * source, bcb_uint128 destination);
// Convert 64 byte hex string 'source' to a byte array 'destination'
// Return 0 on success, nonzero on error
int bcb_uint256_from_string (const char * source, bcb_uint256 destination);
// Convert 128 byte hex string 'source' to a byte array 'destination'
// Return 0 on success, nonzero on error
int bcb_uint512_from_string (const char * source, bcb_uint512 destination);

// Check if the null-terminated string 'account' is a valid bcb account number
// Return 0 on correct, nonzero on invalid
int bcb_valid_address (const char * account);

// Create a new random number in to 'destination'
void bcb_generate_random (bcb_uint256 destination);
// Retrieve the deterministic private key for 'seed' at 'index'
void bcb_seed_key (const bcb_uint256 seed, int index, bcb_uint256);
// Derive the public key 'pub' from 'key'
void bcb_key_account (bcb_uint256 key, bcb_uint256 pub);

// Sign 'transaction' using 'private_key' and write to 'signature'
char * bcb_sign_transaction (const char * transaction, const bcb_uint256 private_key);
// Generate work for 'transaction'
char * bcb_work_transaction (const char * transaction);

#if __cplusplus
} // extern "C"
#endif

#endif // BCB_INTERFACE_H
