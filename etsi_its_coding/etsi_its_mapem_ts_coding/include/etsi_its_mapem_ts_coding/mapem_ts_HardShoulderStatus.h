/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=mapem_ts_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_mapem_ts_HardShoulderStatus_H_
#define	_mapem_ts_HardShoulderStatus_H_


#include <etsi_its_mapem_ts_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_mapem_ts_coding/NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum mapem_ts_HardShoulderStatus {
	mapem_ts_HardShoulderStatus_availableForStopping	= 0,
	mapem_ts_HardShoulderStatus_closed	= 1,
	mapem_ts_HardShoulderStatus_availableForDriving	= 2
} e_mapem_ts_HardShoulderStatus;

/* mapem_ts_HardShoulderStatus */
typedef long	 mapem_ts_HardShoulderStatus_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_mapem_ts_HardShoulderStatus_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_mapem_ts_HardShoulderStatus;
extern const asn_INTEGER_specifics_t asn_SPC_mapem_ts_HardShoulderStatus_specs_1;
asn_struct_free_f mapem_ts_HardShoulderStatus_free;
asn_struct_print_f mapem_ts_HardShoulderStatus_print;
asn_constr_check_f mapem_ts_HardShoulderStatus_constraint;
per_type_decoder_f mapem_ts_HardShoulderStatus_decode_uper;
per_type_encoder_f mapem_ts_HardShoulderStatus_encode_uper;
per_type_decoder_f mapem_ts_HardShoulderStatus_decode_aper;
per_type_encoder_f mapem_ts_HardShoulderStatus_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _mapem_ts_HardShoulderStatus_H_ */
#include <etsi_its_mapem_ts_coding/asn_internal.h>
