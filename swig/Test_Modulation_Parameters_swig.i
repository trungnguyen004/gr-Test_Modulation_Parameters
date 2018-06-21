/* -*- c++ -*- */

#define TEST_MODULATION_PARAMETERS_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "Test_Modulation_Parameters_swig_doc.i"

%{
#include "Test_Modulation_Parameters/OOK_Modulation_para.h"
%}


%include "Test_Modulation_Parameters/OOK_Modulation_para.h"
GR_SWIG_BLOCK_MAGIC2(Test_Modulation_Parameters, OOK_Modulation_para);
