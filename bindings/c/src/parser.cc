// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "vw/experimental/parser.h"

#include "error_handling.h"
VW_DLL_PUBLIC VWStatus vw_create_example_array_holder(VWExampleArrayHolder** example_array_holder_handle,
    VWErrorString* err_str_container, void* factory_context, VWExampleFactoryFunc* factory, void* cleanup_context,
    VWExampleCleanupFunc* cleanup) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)
VW_DLL_PUBLIC VWStatus vw_destroy_example_array_holder(
    VWExampleArrayHolder* example_array_holder_handle, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

// Start the parser+driver loops
VW_DLL_PUBLIC VWStatus vw_run_parser_and_driver(
    VWWorkspace* workspace_handle, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

// Might return a multiline example in the case of the json parser
VW_DLL_PUBLIC VWStatus vw_parse_example(VWWorkspace* workspace_handle, /*const*/ uint8_t* data, size_t length,
    VWInputType type, VWExampleArrayHolder* example_array_holder_handle, VWExample*** produced_examples,
    size_t* num_examples_produced, VWExampleFactoryFunc* factory, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)
