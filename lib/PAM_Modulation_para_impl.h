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

#ifndef INCLUDED_TEST_MODULATION_PARAMETERS_PAM_MODULATION_PARA_IMPL_H
#define INCLUDED_TEST_MODULATION_PARAMETERS_PAM_MODULATION_PARA_IMPL_H

#include <Test_Modulation_Parameters/PAM_Modulation_para.h>

namespace gr {
  namespace Test_Modulation_Parameters {

    class PAM_Modulation_para_impl : public PAM_Modulation_para
    {
     private:
	float my_val00;
	float my_val01;
	float my_val10;
	float my_val11;

     public:
      PAM_Modulation_para_impl(float val00, float val01, float val10, float val11);
      ~PAM_Modulation_para_impl();

	void d_val00(float val00) {my_val00 = val00;}
	float val00() {return my_val00;}
	void d_val01(float val01) {my_val01 = val01;}
	float val01() {return my_val01;}
	void d_val10(float val10) {my_val10 = val10;}
	float val10() {return my_val10;}
	void d_val11(float val11) {my_val11 = val11;}
	float val11() {return my_val11;}

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace Test_Modulation_Parameters
} // namespace gr

#endif /* INCLUDED_TEST_MODULATION_PARAMETERS_PAM_MODULATION_PARA_IMPL_H */

