/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=denm_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_denm_SemiAxisLength_H_
#define	_denm_SemiAxisLength_H_


#include <etsi_its_denm_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_denm_coding/NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum denm_SemiAxisLength {
	denm_SemiAxisLength_oneCentimeter	= 1,
	denm_SemiAxisLength_outOfRange	= 4094,
	denm_SemiAxisLength_unavailable	= 4095
} e_denm_SemiAxisLength;

/* denm_SemiAxisLength */
typedef long	 denm_SemiAxisLength_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_denm_SemiAxisLength_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_denm_SemiAxisLength;
asn_struct_free_f denm_SemiAxisLength_free;
asn_struct_print_f denm_SemiAxisLength_print;
asn_constr_check_f denm_SemiAxisLength_constraint;
per_type_decoder_f denm_SemiAxisLength_decode_uper;
per_type_encoder_f denm_SemiAxisLength_encode_uper;
per_type_decoder_f denm_SemiAxisLength_decode_aper;
per_type_encoder_f denm_SemiAxisLength_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _denm_SemiAxisLength_H_ */
#include <etsi_its_denm_coding/asn_internal.h>
