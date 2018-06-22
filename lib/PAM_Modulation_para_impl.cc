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
#include "PAM_Modulation_para_impl.h"

namespace gr {
  namespace Test_Modulation_Parameters {

    PAM_Modulation_para::sptr
    PAM_Modulation_para::make(float val00, float val01, float val10, float val11)
    {
      return gnuradio::get_initial_sptr
        (new PAM_Modulation_para_impl(val00,val01,val10,val11));
    }

    /*
     * The private constructor
     */
    PAM_Modulation_para_impl::PAM_Modulation_para_impl(float val00, float val01, float val10, float val11)
      : gr::sync_decimator("PAM_Modulation_para",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)), 2) //Later on, if the number of bits change, change this
    {
	d_val00(val00);	
	d_val01(val01);
	d_val10(val10);
	d_val11(val11);

	}

    /*
     * Our virtual destructor.
     */
    PAM_Modulation_para_impl::~PAM_Modulation_para_impl()
    {
    }

    int
    PAM_Modulation_para_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];

      int i = 0;
      int j = 0;
      int ctr = 0;
      
      while(i < noutput_items) {
	if(in[j] < 0.5 and in[j+1] < 0.5)
		{ out[i++] = val00();
		  j+=2;}
	if(in[j] < 0.5 and in[j+1] > 0.5)
		{ out[i++] = val01();
		  j+=2;}
	if(in[j] > 0.5 and in[j+1] < 0.5)
		{ out[i++] = val10();
		  j+=2;}
	if(in[j] > 0.5 and in[j+1] > 0.5)
		{ out[i++] = val11();
		  j+=2;}
	

      }

      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace Test_Modulation_Parameters */
} /* namespace gr */

