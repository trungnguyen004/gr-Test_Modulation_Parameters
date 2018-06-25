/* -*- c++ -*- */
/* 
 * Copyright 2018 Jason.
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
#include "OOK_Demodulation_para_impl.h"

namespace gr {
  namespace Test_Modulation_Parameters {

    OOK_Demodulation_para::sptr
    OOK_Demodulation_para::make(float thresthold)  
    {
      return gnuradio::get_initial_sptr
        (new OOK_Demodulation_para_impl(thresthold));
    }

    /*
     * The private constructor
     */
    OOK_Demodulation_para_impl::OOK_Demodulation_para_impl(float thresthold)
      : gr::block("OOK_Demodulation_para",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)))
    {
	d_thresthold(thresthold);
	}

    /*
     * Our virtual destructor.
     */
    OOK_Demodulation_para_impl::~OOK_Demodulation_para_impl()
    {
    }

    void
    OOK_Demodulation_para_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      ninput_items_required[0] = noutput_items;
    }

    int
    OOK_Demodulation_para_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];

	for(int i =0; i < noutput_items; i++) {
	 if (in[i] < thresthold()) 
		{out[i] = 0;}
	 if (in[i] >= thresthold())
		{out[i] = 1;}
	}

     
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace Test_Modulation_Parameters */
} /* namespace gr */

