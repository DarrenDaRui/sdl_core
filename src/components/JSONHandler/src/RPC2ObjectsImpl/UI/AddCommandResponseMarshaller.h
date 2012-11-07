#ifndef RPC2COMMUNICATION_UI_ADDCOMMANDRESPONSEMARSHALLER_INCLUDE
#define RPC2COMMUNICATION_UI_ADDCOMMANDRESPONSEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/RPC2Objects/UI/AddCommandResponse.h"

namespace RPC2Communication
{
  namespace UI
  {

    struct AddCommandResponseMarshaller
    {
      static bool checkIntegrity(AddCommandResponse& e);
      static bool checkIntegrityConst(const AddCommandResponse& e);
    
      static bool fromString(const std::string& s,AddCommandResponse& e);
      static const std::string toString(const AddCommandResponse& e);
    
      static bool fromJSON(const Json::Value& s,AddCommandResponse& e);
      static Json::Value toJSON(const AddCommandResponse& e);
    };
  }
}

#endif
