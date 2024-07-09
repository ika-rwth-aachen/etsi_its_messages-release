/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=denm_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_denm_PhoneNumber_H_
#define	_denm_PhoneNumber_H_


#include <etsi_its_denm_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_denm_coding/NumericString.h>

#ifdef __cplusplus
extern "C" {
#endif

/* denm_PhoneNumber */
typedef NumericString_t	 denm_PhoneNumber_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_denm_PhoneNumber_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_denm_PhoneNumber;
asn_struct_free_f denm_PhoneNumber_free;
asn_struct_print_f denm_PhoneNumber_print;
asn_constr_check_f denm_PhoneNumber_constraint;
per_type_decoder_f denm_PhoneNumber_decode_uper;
per_type_encoder_f denm_PhoneNumber_encode_uper;
per_type_decoder_f denm_PhoneNumber_decode_aper;
per_type_encoder_f denm_PhoneNumber_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _denm_PhoneNumber_H_ */
#include <etsi_its_denm_coding/asn_internal.h>
