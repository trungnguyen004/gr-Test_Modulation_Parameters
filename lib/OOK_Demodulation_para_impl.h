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

#ifndef INCLUDED_TEST_MODULATION_PARAMETERS_OOK_DEMODULATION_PARA_IMPL_H
#define INCLUDED_TEST_MODULATION_PARAMETERS_OOK_DEMODULATION_PARA_IMPL_H

#include <Test_Modulation_Parameters/OOK_Demodulation_para.h>

namespace gr {
  namespace Test_Modulation_Parameters {

    class OOK_Demodulation_para_impl : public OOK_Demodulation_para
    {
     private:
      float my_thresthold;

     public:
      OOK_Demodulation_para_impl(float thresthold);
      ~OOK_Demodulation_para_impl();

	void d_thresthold(float thresthold) {my_thresthold = thresthold;}
	float thresthold() {return my_thresthold;}

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace Test_Modulation_Parameters
} // namespace gr

#endif /* INCLUDED_TEST_MODULATION_PARAMETERS_OOK_DEMODULATION_PARA_IMPL_H */

