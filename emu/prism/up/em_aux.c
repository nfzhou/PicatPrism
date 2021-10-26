/* -*- c-basic-offset: 2; tab-width: 8 -*- */

/*------------------------------------------------------------------------*/

#include "bprolog.h"
#include "up/up.h"
#include "up/graph.h"
#include "up/flags.h"

/*------------------------------------------------------------------------*/

int *  num_sw_vals = NULL;
double itemp;
double inside_failure;
int    failure_observed;

/*------------------------------------------------------------------------*/

/* mic.c (B-Prolog) */
void quit(CHAR_PTR);

/*------------------------------------------------------------------------*/

static int compare_sw_ins(const void *a, const void *b) {
	SW_INS_PTR sw_ins_a, sw_ins_b;
	TERM msw_a, msw_b;

	sw_ins_a = *(const SW_INS_PTR *)(a);
	sw_ins_b = *(const SW_INS_PTR *)(b);

	msw_a = prism_sw_ins_term(sw_ins_a->id);
	msw_b = prism_sw_ins_term(sw_ins_b->id);

	return bpx_compare(bpx_get_arg(1,msw_a), bpx_get_arg(1,msw_b));
}

void sort_occ_switches(void) {
	qsort(occ_switches,occ_switch_tab_size,sizeof(SW_INS_PTR),compare_sw_ins);
}

/*------------------------------------------------------------------------*/

/* Set flags of switches appearing in the e-graphs and allocate an array
 * of pointers to such switches (This routine is based on compute_inside()).
 */
void alloc_occ_switches(void) {
	int i,j,k;
	EG_NODE_PTR eg_ptr;
	EG_PATH_PTR path_ptr;
	SW_INS_PTR sw_ins_ptr;
	int *occ_sw_flags;
	int b;

	/* Initialize the `occ' counters in switch instances */
	for (i = 0; i < sw_ins_tab_size; i++) {
		switch_instances[i]->occ = 0;
	}

	for (i = 0; i < sorted_egraph_size; i++) {
		eg_ptr = sorted_expl_graph[i];
		path_ptr = eg_ptr->path_ptr;
		while (path_ptr != NULL) {
			for (k = 0; k < path_ptr->sws_len; k++) {
				path_ptr->sws[k]->occ = 1;
			}
			path_ptr = path_ptr->next;
		}
	}

	/* Temporarily make an array of flags each of which indicates whether
	   a switch (not switch instance) occurs in the e-graphs */
	occ_sw_flags = (int *)MALLOC(sizeof(int) * sw_tab_size);
	occ_switch_tab_size = 0;
	for (i = 0; i < sw_tab_size; i++) {
		sw_ins_ptr = switches[i];
		b = 0;
		while (sw_ins_ptr != NULL) {
			b |= sw_ins_ptr->occ;
			sw_ins_ptr = sw_ins_ptr->next;
		}
		occ_sw_flags[i] = b;
		if (b) occ_switch_tab_size++;
	}

	occ_switches = (SW_INS_PTR *)MALLOC(sizeof(SW_INS_PTR) * occ_switch_tab_size);

	j = 0;
	for (i = 0; i < sw_tab_size; i++) {
		if (occ_sw_flags[i]) {
			occ_switches[j] = switches[i];  /* Copy */
			j++;
		}
	}

	free(occ_sw_flags);

	if (fix_init_order) {
		sort_occ_switches();
	}
}

void release_occ_switches(void) {
	FREE(occ_switches);
}

void alloc_num_sw_vals(void) {
	int i,n;
	SW_INS_PTR sw_ins_ptr;

	num_sw_vals = (int *)MALLOC(sizeof(int) * occ_switch_tab_size);

	for (i = 0; i < occ_switch_tab_size; i++) {
		sw_ins_ptr = occ_switches[i];
		n = 0;
		while (sw_ins_ptr != NULL) {
			n++;
			sw_ins_ptr = sw_ins_ptr->next;
		}
		num_sw_vals[i] = n;
	}
}

void release_num_sw_vals(void) {
	FREE(num_sw_vals);
}

/*------------------------------------------------------------------------*/

void transfer_hyperparams_prolog(void) {
	int i;
	SW_INS_PTR sw_ins_ptr;

	for (i = 0; i < occ_switch_tab_size; i++) {
		sw_ins_ptr = occ_switches[i];
		while (sw_ins_ptr != NULL) {
			sw_ins_ptr->smooth   = sw_ins_ptr->smooth_prolog;
			sw_ins_ptr->inside_h = sw_ins_ptr->smooth_prolog + 1.0;
			sw_ins_ptr = sw_ins_ptr->next;
		}
	}
}

/*------------------------------------------------------------------------*/
