/*
 * Tools.h
 *
 *  Created on: Apr 25, 2013
 *      Author: kowalisz
 */

#ifndef TOOLS_H_
#define TOOLS_H_


#include <string.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

template <typename T> T CLAMP(const T& value, const T& low, const T& high)
{
  T tmp = value < low ? low : (value > high ? high : value);
  return tmp;
};

std::vector<std::string> string2vector(std::string &str, const char* tokens);


#ifdef REG_TEST_ENV

#include <omnithread.h>

#define EXCEPTION_RETURN(_a, _b, _c) throw(string(_a) + " - " + string(_b) + " - " + string(_c))
#define LOGGING_ADDONS
#define LOGGING_INITIALIZE_ADDON( _ref_ )
#define LOGGING_INITIALIZE_WITH_LOGGER_REF_ADDON( _ref_, _logger_ref_ )

#define DEBUG_STREAM cout
#define INFO_STREAM cout
#define ERROR_STREAM cerr
#define DB_ERROR_STREAM cerr
#define DB_INFO_STREAM cout
#define DB_DEBUG_STREAM cout

#else

#include <tango.h>

#define EXCEPTION_RETURN(_a, _b, _c) Tango::Except::throw_exception(_c, _b, _a)

#define LOGGING_ADDONS 		private:\
		log4tango::Logger* _logger;\
		public:\
		log4tango::Logger* get_logger (void) const { return _logger; };\
		void set_logger(log4tango::Logger* lRef) { _logger = lRef; }

#define LOGGING_INITIALIZE_ADDON( _ref_ )  _ref_->set_logger(_logger)
#define LOGGING_INITIALIZE_WITH_LOGGER_REF_ADDON( _ref_, _logger_ref_ )  _ref_->set_logger(_logger_ref_)

#define DB_ERROR_STREAM cerr
#define DB_INFO_STREAM TANGO_LOG_INFO
#define DB_DEBUG_STREAM TANGO_LOG_DEBUG

#endif

#endif /* TOOLS_H_ */
