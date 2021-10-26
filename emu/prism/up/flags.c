/* -*- c-basic-offset: 4 ; tab-width: 4 -*- */

/*------------------------------------------------------------------------*/

#include "bprolog.h"
#include "up/up.h"

/*------------------------------------------------------------------------*/

/*
 * Since these variables are initialized on start-up by the predicate
 * reset_prism_flags/0, the initial values below are not actually used.
 * The values are just for reference.
 *
 * Also, don't forget to modify mp_flags.c when adding new flags.
 */
int     daem                  = 0;
int     em_message            = 1;
int     em_progress           = 10;
int     error_on_cycle        = 1;
int     explicit_empty_expls  = 1;
int     fix_init_order        = 1;
int     init_method           = 1;
double  itemp_init            = 0.1;
double  itemp_rate            = 1.2;
int     log_scale             = 0;
int     max_iterate           = -1; /* == DEFAULT_MAX_ITERATE */
int     mcmc_message          = 1;
int     mcmc_progress         = 100;
int     num_restart           = 1;
double  prism_epsilon         = 0.0001;
int     show_itemp            = 0;
double  std_ratio             = 0.1;
int     verb_em               = 0;
int     verb_graph            = 0;
int     warn                  = 0;
/*for D-PRISM*/
double  annealing_weight      = 1.0;
int     crf_learning_rate     = 0;
double  crf_epsilon           = 1.0;
double  crf_golden_b          = 1.0;
int     crf_init_method       = 3;
int     crf_learn_mode        = 0;
double  crf_ls_rho            = 0.5;
double  crf_ls_c1             = 0.5;
double  crf_penalty           = 0.0;
/*for cyclic*/
int     scc_debug_level       = 0;
/*for sgd*/
int     sgd_optimizer         = 2;
double  sgd_learning_rate     = 0.01;
double  sgd_penalty           = 0.1;
int     num_minibatch         = 1;
double  sgd_adam_beta         = 0.9;
double  sgd_adam_gamma        = 0.999;
double  sgd_adam_epsilon      = 1.0e-8;
double  sgd_adadelta_gamma    = 0.95;
double  sgd_adadelta_epsilon  = 1.0e-8;
/*fro rank*/
double  rank_loss_c                = 1;
int     rank_loss             = 0;

/*
 * This variable does not correspond to any prism flags, and hence is
 * not initialized by reset_prism_flags/0.
 */
int     debug_level         = 0;

/*------------------------------------------------------------------------*/

int pc_set_daem_1(void) {
	daem = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_em_message_1(void) {
	em_message = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_em_progress_1(void) {
	em_progress = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_error_on_cycle_1(void) {
	error_on_cycle = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_explicit_empty_expls_1(void) {
	explicit_empty_expls = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_fix_init_order_1(void) {
	fix_init_order = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_init_method_1(void) {
	init_method = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_itemp_init_1(void) {
	itemp_init = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_itemp_rate_1(void) {
	itemp_rate = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_log_scale_1(void) {
	log_scale = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_max_iterate_1(void) {
	max_iterate = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_mcmc_message_1(void) {
	mcmc_message = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_mcmc_progress_1(void) {
	mcmc_progress = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_num_restart_1(void) {
	num_restart = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_prism_epsilon_1(void) {
	prism_epsilon = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_show_itemp_1(void) {
	show_itemp = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_std_ratio_1(void) {
	std_ratio = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_verb_em_1(void) {
	verb_em = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_verb_graph_1(void) {
	verb_graph = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_warn_1(void) {
	warn = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_debug_level_1(void) {
	debug_level = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_annealing_weight_1(void) {
	annealing_weight = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_crf_learning_rate_1(void) {
	crf_learning_rate = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_crf_epsilon_1(void) {
	crf_epsilon = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_crf_golden_b_1(void) {
	crf_golden_b = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_crf_init_method_1(void) {
	crf_init_method = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_crf_learn_mode_1(void) {
	crf_learn_mode = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_crf_ls_rho_1(void) {
	crf_ls_rho = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_crf_ls_c1_1(void) {
	crf_ls_c1 = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_crf_penalty_1(void) {
	crf_penalty = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_scc_debug_level_1(void) {
	scc_debug_level = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_sgd_penalty_1(void) {
	sgd_penalty = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_sgd_optimizer_1(void) {
	sgd_optimizer = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}


int pc_set_sgd_learning_rate_1(void) {
	sgd_learning_rate = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_num_minibatch_1(void) {
	num_minibatch = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}

int pc_set_sgd_adam_beta_1(void) {
	sgd_adam_beta = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}
int pc_set_sgd_adam_gamma_1(void) {
	sgd_adam_gamma = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}
int pc_set_sgd_adam_epsilon_1(void) {
	sgd_adam_epsilon = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}
int pc_set_sgd_adadelta_gamma_1(void) {
	sgd_adadelta_gamma = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}
int pc_set_sgd_adadelta_epsilon_1(void) {
	sgd_adadelta_epsilon = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}
int pc_set_rank_loss_1(void) {
	rank_loss = bpx_get_integer(bpx_get_call_arg(1,1));
	return BP_TRUE;
}
int pc_set_rank_loss_c_1(void) {
	rank_loss_c = bpx_get_float(bpx_get_call_arg(1,1));
	return BP_TRUE;
}


/*------------------------------------------------------------------------*/
