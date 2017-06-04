#ifndef WEBAPI_MODULE_CORE_H
#define WEBAPI_MODULE_CORE_H

/** The block below describes the properties of this module, and is read by
	the Projucer to automatically generate project code that uses it.

    BEGIN_JUCE_MODULE_DECLARATION

    ID:             webapi_core
    vendor:         jrlanglois
    version:        0.0.1
    name:           WebAPI Core
    description:    The root module driving the REST APIs modules.
    website:        https://github.com/jrlanglois/WebAPI
    license:        MIT

    dependencies:   juce_data_structures juce_cryptography

    END_JUCE_MODULE_DECLARATION
*/
//==============================================================================
#include <juce_data_structures/juce_data_structures.h>
#include <juce_cryptography/juce_cryptography.h>

//==============================================================================
namespace webapi
{
    using namespace juce;

    #include "core/webapi_oauth.h"
}

#endif //WEBAPI_MODULE_CORE_H
