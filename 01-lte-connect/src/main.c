
#include <stdio.h>
#include <ncs_version.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <dk_buttons_and_leds.h>

/* Include the header file of the nRF Modem library and the LTE link controller library */
#include <modem/nrf_modem_lib.h>
#include <modem/lte_lc.h>

/* The semaphore lte_connected */
static K_SEM_DEFINE(lte_connected, 0, 1);

static int modem_configure(void);

LOG_MODULE_REGISTER(LTE-Conn, LOG_LEVEL_INF);

/* The event handler for LTE link control */
static void lte_handler(const struct lte_lc_evt *const evt)
{
	switch (evt->type) {
	/* On changed registration status, print status */
	case LTE_LC_EVT_NW_REG_STATUS:
		if ((evt->nw_reg_status != LTE_LC_NW_REG_REGISTERED_HOME) &&
			(evt->nw_reg_status != LTE_LC_NW_REG_REGISTERED_ROAMING)) {
			break;
		}

		LOG_INF("Network registration status: %s",
			evt->nw_reg_status == LTE_LC_NW_REG_REGISTERED_HOME ?
			"Connected - home network" : "Connected - roaming");
		k_sem_give(&lte_connected);
		break;

	/* On event RRC update, print RRC mode */
	case LTE_LC_EVT_RRC_UPDATE:
		LOG_INF("RRC mode: %s", evt->rrc_mode == LTE_LC_RRC_MODE_CONNECTED ? 
				"Connected" : "Idle");
		break;		

	default:
		break;
	}
}

int main(void)
{
	int err;

	if (dk_leds_init() != 0) {
		LOG_ERR("Failed to initialize the LEDs Library");
	}

	/* Call modem_configure() to initiate the LTE connection */
	err = modem_configure();
	if (err) {
		LOG_ERR("Failed to configure the modem");
		return 0;
	}

	/* Take the semaphore lte_connected */
	k_sem_take(&lte_connected, K_FOREVER);

	LOG_INF("Connected to LTE network");

	/* Turn on the LED status LED */
	dk_set_led_on(DK_LED2);

	return 0;
}

static int modem_configure(void)
{
	int err;

	LOG_INF("Initializing modem library");
	err = nrf_modem_lib_init();
	if (err) {
		LOG_ERR("Failed to initialize the modem library, error: %d", err);
		return err;
	}
	
	LOG_INF("Connecting to LTE network");
	err = lte_lc_connect_async(lte_handler);
	if (err) {
		LOG_ERR("Error in lte_lc_connect_async, error: %d", err);
		return err;
	}
	return 0;
}
