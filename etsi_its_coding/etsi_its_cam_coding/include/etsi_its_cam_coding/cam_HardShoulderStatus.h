/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=cam_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_cam_HardShoulderStatus_H_
#define	_cam_HardShoulderStatus_H_


#include <etsi_its_cam_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_cam_coding/NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum cam_HardShoulderStatus {
	cam_HardShoulderStatus_availableForStopping	= 0,
	cam_HardShoulderStatus_closed	= 1,
	cam_HardShoulderStatus_availableForDriving	= 2
} e_cam_HardShoulderStatus;

/* cam_HardShoulderStatus */
typedef long	 cam_HardShoulderStatus_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_cam_HardShoulderStatus_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_cam_HardShoulderStatus;
extern const asn_INTEGER_specifics_t asn_SPC_cam_HardShoulderStatus_specs_1;
asn_struct_free_f cam_HardShoulderStatus_free;
asn_struct_print_f cam_HardShoulderStatus_print;
asn_constr_check_f cam_HardShoulderStatus_constraint;
per_type_decoder_f cam_HardShoulderStatus_decode_uper;
per_type_encoder_f cam_HardShoulderStatus_encode_uper;
per_type_decoder_f cam_HardShoulderStatus_decode_aper;
per_type_encoder_f cam_HardShoulderStatus_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _cam_HardShoulderStatus_H_ */
#include <etsi_its_cam_coding/asn_internal.h>