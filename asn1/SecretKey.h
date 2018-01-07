/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "KeyContainer"
 * 	found in "KeyContainer.asn1"
 * 	`asn1c -fwide-types -pdu=all`
 */

#ifndef	_SecretKey_H_
#define	_SecretKey_H_


#include <asn_application.h>

/* Including external dependencies */
#include "EncodedKeyValue.h"
#include <OBJECT_IDENTIFIER.h>
#include <OCTET_STRING.h>
#include "KeyProtectParameters.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct KeyResource;

/* SecretKey */
typedef struct SecretKey {
	EncodedKeyValue_t	 value;
	OBJECT_IDENTIFIER_t	 engine;
	OCTET_STRING_t	 number;
	KeyProtectParameters_t	 parameters;
	struct KeyResource	*resource	/* OPTIONAL */;
	OCTET_STRING_t	*description	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SecretKey_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SecretKey;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "KeyResource.h"

#endif	/* _SecretKey_H_ */
#include <asn_internal.h>