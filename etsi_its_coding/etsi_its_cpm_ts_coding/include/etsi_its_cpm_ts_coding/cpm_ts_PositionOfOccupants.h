/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "/input/ETSI-ITS-CDD.asn"
 * 	`asn1c -fcompound-names -fprefix=cpm_ts_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_cpm_ts_PositionOfOccupants_H_
#define	_cpm_ts_PositionOfOccupants_H_


#include <etsi_its_cpm_ts_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_cpm_ts_coding/BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum cpm_ts_PositionOfOccupants {
	cpm_ts_PositionOfOccupants_row1LeftOccupied	= 0,
	cpm_ts_PositionOfOccupants_row1RightOccupied	= 1,
	cpm_ts_PositionOfOccupants_row1MidOccupied	= 2,
	cpm_ts_PositionOfOccupants_row1NotDetectable	= 3,
	cpm_ts_PositionOfOccupants_row1NotPresent	= 4,
	cpm_ts_PositionOfOccupants_row2LeftOccupied	= 5,
	cpm_ts_PositionOfOccupants_row2RightOccupied	= 6,
	cpm_ts_PositionOfOccupants_row2MidOccupied	= 7,
	cpm_ts_PositionOfOccupants_row2NotDetectable	= 8,
	cpm_ts_PositionOfOccupants_row2NotPresent	= 9,
	cpm_ts_PositionOfOccupants_row3LeftOccupied	= 10,
	cpm_ts_PositionOfOccupants_row3RightOccupied	= 11,
	cpm_ts_PositionOfOccupants_row3MidOccupied	= 12,
	cpm_ts_PositionOfOccupants_row3NotDetectable	= 13,
	cpm_ts_PositionOfOccupants_row3NotPresent	= 14,
	cpm_ts_PositionOfOccupants_row4LeftOccupied	= 15,
	cpm_ts_PositionOfOccupants_row4RightOccupied	= 16,
	cpm_ts_PositionOfOccupants_row4MidOccupied	= 17,
	cpm_ts_PositionOfOccupants_row4NotDetectable	= 18,
	cpm_ts_PositionOfOccupants_row4NotPresent	= 19
} e_cpm_ts_PositionOfOccupants;

/* cpm_ts_PositionOfOccupants */
typedef BIT_STRING_t	 cpm_ts_PositionOfOccupants_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_cpm_ts_PositionOfOccupants;
asn_struct_free_f cpm_ts_PositionOfOccupants_free;
asn_struct_print_f cpm_ts_PositionOfOccupants_print;
asn_constr_check_f cpm_ts_PositionOfOccupants_constraint;
per_type_decoder_f cpm_ts_PositionOfOccupants_decode_uper;
per_type_encoder_f cpm_ts_PositionOfOccupants_encode_uper;
per_type_decoder_f cpm_ts_PositionOfOccupants_decode_aper;
per_type_encoder_f cpm_ts_PositionOfOccupants_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _cpm_ts_PositionOfOccupants_H_ */
#include <etsi_its_cpm_ts_coding/asn_internal.h>
