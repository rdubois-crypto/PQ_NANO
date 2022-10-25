/*****************************************************************************
 *   Ledger App PQ NANO.
 *****************************************************************************/


#include <stdint.h>   // uint*_t
#include <stdbool.h>  // bool
#include <stddef.h>   // size_t
#include <string.h>   // memset, explicit_bzero

#include "os.h"
#include "cx.h"

#include "compute_pedersen.h"
#include "../sw.h"
#include "../globals.h"
#include "../crypto.h"
#include "../ui/display.h"
#include "../ui/action/validate.h"
#include "../common/buffer.h"
#include "../transaction/types.h"
#include "../transaction/deserialize.h"
#include "../falcon512cxm4/api.h"
#include "../helper/send_response.h"


int handler_compute_kgfalcon(buffer_t *cdata, uint8_t n) {


	explicit_bzero(&G_context, sizeof(G_context));
	G_context.req_type = COMPUTE_FALCONKG;
    G_context.state = STATE_NONE;

    /* todo: seed the prng of keygen with apdu input */
	if (!buffer_move(cdata, G_context.pn_info.ab, 64)) {

		return io_send_sw(SW_WRONG_DATA_LENGTH);

    } else {  // Compute Falcon keygen
		G_context.state = STATE_PARSED;


		crypto_sign_keypair(G_context.falcon_info.pk_falcon, G_context.falcon_info.sk_falcon);


		PRINTF("Falcon PubK: %.*h\n", G_context.falcon_info.pk_falcon, G_context.falcon_info.sk_falcon);

		G_context.state = STATE_APPROVED;
		return helper_send_response_falconkg(&G_context.falcon_info);
    }

    return 0;
}
