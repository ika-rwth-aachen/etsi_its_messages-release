/*
 * Generated by asn1c-0.9.29-DF (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-UPER`
 */


/* Including external dependencies */
#include <etsi_its_denm_coding/NativeEnumerated.h>
#ifndef	_StationarySince_H_
#define	_StationarySince_H_


#include <etsi_its_denm_coding/asn_application.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum StationarySince {
	StationarySince_lessThan1Minute	= 0,
	StationarySince_lessThan2Minutes	= 1,
	StationarySince_lessThan15Minutes	= 2,
	StationarySince_equalOrGreater15Minutes	= 3
} e_StationarySince;

/* StationarySince */
typedef long	 StationarySince_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_StationarySince_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_StationarySince;
extern const asn_INTEGER_specifics_t asn_SPC_StationarySince_specs_1;
asn_struct_free_f StationarySince_free;
asn_struct_print_f StationarySince_print;
asn_constr_check_f StationarySince_constraint;
ber_type_decoder_f StationarySince_decode_ber;
der_type_encoder_f StationarySince_encode_der;
xer_type_decoder_f StationarySince_decode_xer;
xer_type_encoder_f StationarySince_encode_xer;
jer_type_encoder_f StationarySince_encode_jer;
oer_type_decoder_f StationarySince_decode_oer;
oer_type_encoder_f StationarySince_encode_oer;
per_type_decoder_f StationarySince_decode_uper;
per_type_encoder_f StationarySince_encode_uper;
per_type_decoder_f StationarySince_decode_aper;
per_type_encoder_f StationarySince_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _StationarySince_H_ */
#include <etsi_its_denm_coding/asn_internal.h>
