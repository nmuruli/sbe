/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/core/p9_sbe_instruct_start.C $ */
/*                                                                        */
/* OpenPOWER sbe Project                                                  */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_sbe_instruct_start.C
///
/// @brief Starts instructions on master core, thread 0.
///        Thread 0 will be started at CIA scan flush value of 0.
//
// *HWP HWP Owner: Nick Klazynski <jklazyns@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_sbe_instruct_start.H>

extern "C"
{

///
/// p9_sbe_instruct_start HWP entry point (Defined in .H file)
///
    fapi2::ReturnCode p9_sbe_instruct_start(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
    {
        fapi2::buffer<uint64_t> l_rasStatusReg(0);
        uint64_t l_state = 0;
        FAPI_DBG("Entering ...");

        FAPI_INF("Starting instruction on thread 0");
        FAPI_TRY(p9_thread_control(i_target, 0b1000, PTC_CMD_START, false,
                                   l_rasStatusReg, l_state),
                 "p9_thread_control() returns an error");

    fapi_try_exit:
        FAPI_DBG("Exiting ...");
        return fapi2::current_err;
    }

} // extern "C"
