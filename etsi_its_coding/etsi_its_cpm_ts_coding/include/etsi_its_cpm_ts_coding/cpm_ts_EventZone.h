/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "/input/ETSI-ITS-CDD.asn"
 * 	`asn1c -fcompound-names -fprefix=cpm_ts_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_cpm_ts_EventZone_H_
#define	_cpm_ts_EventZone_H_


#include <etsi_its_cpm_ts_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_cpm_ts_coding/cpm_ts_EventHistory.h"

#ifdef __cplusplus
extern "C" {
#endif

/* cpm_ts_EventZone */
typedef cpm_ts_EventHistory_t	 cpm_ts_EventZone_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_cpm_ts_EventZone;
asn_struct_free_f cpm_ts_EventZone_free;
asn_struct_print_f cpm_ts_EventZone_print;
asn_constr_check_f cpm_ts_EventZone_constraint;
per_type_decoder_f cpm_ts_EventZone_decode_uper;
per_type_encoder_f cpm_ts_EventZone_encode_uper;
per_type_decoder_f cpm_ts_EventZone_decode_aper;
per_type_encoder_f cpm_ts_EventZone_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _cpm_ts_EventZone_H_ */
#include <etsi_its_cpm_ts_coding/asn_internal.h>
