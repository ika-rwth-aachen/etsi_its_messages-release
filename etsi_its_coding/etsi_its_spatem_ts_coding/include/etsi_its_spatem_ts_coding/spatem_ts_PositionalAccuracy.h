/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "/input/ISO-TS-19091-addgrp-C-2018-patched.asn"
 * 	`asn1c -fcompound-names -fprefix=spatem_ts_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_spatem_ts_PositionalAccuracy_H_
#define	_spatem_ts_PositionalAccuracy_H_


#include <etsi_its_spatem_ts_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_spatem_ts_coding/spatem_ts_SemiMajorAxisAccuracy.h"
#include "etsi_its_spatem_ts_coding/spatem_ts_SemiMinorAxisAccuracy.h"
#include "etsi_its_spatem_ts_coding/spatem_ts_SemiMajorAxisOrientation.h"
#include <etsi_its_spatem_ts_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* spatem_ts_PositionalAccuracy */
typedef struct spatem_ts_PositionalAccuracy {
	spatem_ts_SemiMajorAxisAccuracy_t	 semiMajor;
	spatem_ts_SemiMinorAxisAccuracy_t	 semiMinor;
	spatem_ts_SemiMajorAxisOrientation_t	 orientation;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} spatem_ts_PositionalAccuracy_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_spatem_ts_PositionalAccuracy;
extern asn_SEQUENCE_specifics_t asn_SPC_spatem_ts_PositionalAccuracy_specs_1;
extern asn_TYPE_member_t asn_MBR_spatem_ts_PositionalAccuracy_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _spatem_ts_PositionalAccuracy_H_ */
#include <etsi_its_spatem_ts_coding/asn_internal.h>
