/* -*- c++ -*- */
/* 
 * Copyright 2018 Jason Nguyen.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "OOK_Modulation_para_impl.h"

namespace gr {
  namespace Test_Modulation_Parameters {

    OOK_Modulation_para::sptr
    OOK_Modulation_para::make(float max, float min) // MODIFY THIS TO ADD PARAMETERS
    {
      return gnuradio::get_initial_sptr
        (new OOK_Modulation_para_impl(max, min)); // MODIFY THIS TO ADD PARAMETERS
    }

    /*
     * The private constructor
     */
    OOK_Modulation_para_impl::OOK_Modulation_para_impl(float max,float min) // MODIFY THIS TO ADD PARAMETERS
      : gr::sync_interpolator("OOK_Modulation_para",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)), 2)
    {
	d_max(max);
	d_min(min);
	}

    /*
     * Our virtual destructor.
     */
    OOK_Modulation_para_impl::~OOK_Modulation_para_impl()
    {
    }

    int
    OOK_Modulation_para_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];

	int i=0;
	int j=0;
	int ctr=0;

	while(i < noutput_items) {  
		if (in[j] < 0.5)		// j is for input
			{ out[i++] = min();		// i is for output
			  ctr++;
			 if (ctr >= 2)  {	// This if statement is for counting so that 1 input produces 2 outputs
			  ctr = 0;
			  j++;
					}
			}
		if (in[j] > 0.5)
			{ out[i++] = max();
			  ctr++;
			 if (ctr >= 2)  {
			  ctr = 0;
			  j++;
					}
			}
				}	

      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace Test_Modulation_Parameters */
} /* namespace gr */

