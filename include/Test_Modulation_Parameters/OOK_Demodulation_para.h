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


#ifndef INCLUDED_TEST_MODULATION_PARAMETERS_OOK_DEMODULATION_PARA_H
#define INCLUDED_TEST_MODULATION_PARAMETERS_OOK_DEMODULATION_PARA_H

#include <Test_Modulation_Parameters/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace Test_Modulation_Parameters {

    /*!
     * \brief <+description of block+>
     * \ingroup Test_Modulation_Parameters
     *
     */
    class TEST_MODULATION_PARAMETERS_API OOK_Demodulation_para : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<OOK_Demodulation_para> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of Test_Modulation_Parameters::OOK_Demodulation_para.
       *
       * To avoid accidental use of raw pointers, Test_Modulation_Parameters::OOK_Demodulation_para's
       * constructor is in a private implementation
       * class. Test_Modulation_Parameters::OOK_Demodulation_para::make is the public interface for
       * creating new instances.
       */
      static sptr make(float thresthold);
	virtual void d_thresthold(float thresthold) = 0;
	virtual float thresthold() = 0;
    };

  } // namespace Test_Modulation_Parameters
} // namespace gr

#endif /* INCLUDED_TEST_MODULATION_PARAMETERS_OOK_DEMODULATION_PARA_H */

