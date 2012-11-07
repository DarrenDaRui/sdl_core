#include "../include/JSONHandler/RPC2Objects/UI/PerformInteractionResponse.h"
#include "../src/ALRPCObjectsImpl/TriggerSourceMarshaller.h"
#include "../src/ALRPCObjectsImpl/ResultMarshaller.h"
#include "PerformInteractionResponseMarshaller.h"

/*
  interface	RPC2Communication::UI
  version	1.2
  generated at	Wed Nov  7 11:26:14 2012
  source stamp	Wed Nov  7 09:29:07 2012
  author	robok0der
*/

using namespace RPC2Communication;
using namespace AppLinkRPC;
using namespace RPC2Communication::UI;

bool PerformInteractionResponseMarshaller::checkIntegrity(PerformInteractionResponse& s)
{
  return checkIntegrityConst(s);
}


bool PerformInteractionResponseMarshaller::fromString(const std::string& s,PerformInteractionResponse& e)
{
  try
  {
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(s,json,false))  return false;
    if(!fromJSON(json,e))  return false;
  }
  catch(...)
  {
    return false;
  }
  return true;
}


const std::string PerformInteractionResponseMarshaller::toString(const PerformInteractionResponse& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool PerformInteractionResponseMarshaller::checkIntegrityConst(const PerformInteractionResponse& s)
{
  if(s.choiceID && (s.choiceID[0]>2000000000))  return false;

  if(s.triggerSource && (!TriggerSourceMarshaller::checkIntegrityConst(s.triggerSource[0])))  return false;

  return true;
}


Json::Value PerformInteractionResponseMarshaller::toJSON(const PerformInteractionResponse& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["jsonrpc"]=Json::Value("2.0");
  json["id"]=Json::Value(e.getId());
  json["result"]=Json::Value(Json::objectValue);
  AppLinkRPC::Result r(static_cast<AppLinkRPC::Result::ResultInternal>(e.getResult()));
  json["result"]["_Result"]=AppLinkRPC::ResultMarshaller::toJSON(r);
  json["result"]["_Method"]=Json::Value("UI.PerformInteractionResponse");

  if(e.choiceID)
    json["result"]["choiceID"]=Json::Value(e.choiceID[0]);;
  if(e.triggerSource)
    json["result"]["triggerSource"]=TriggerSourceMarshaller::toJSON(e.triggerSource[0]);;
  return json;
}


bool PerformInteractionResponseMarshaller::fromJSON(const Json::Value& json,PerformInteractionResponse& c)
{
  try
  {
    if(!json.isObject())  return false;
    if(!json.isMember("jsonrpc") || !json["jsonrpc"].isString() || json["jsonrpc"].asString().compare("2.0"))  return false;
    if(!json.isMember("id") || !json["id"].isInt()) return false;
    c.setId(json["id"].asInt());

    if(!json.isMember("result")) return false;

    Json::Value js=json["result"];
    if(!js.isObject())  return false;

    Result r;
    if(!js.isMember("_Result") || !js["_Result"].isString())  return false;
    if(!js.isMember("_Method") || !js["_Method"].isString())  return false;
    if(js["_Method"].asString().compare("UI.PerformInteractionResponse")) return false;

    if(!AppLinkRPC::ResultMarshaller::fromJSON(js["_Result"],r))  return false;
    c.setResult(r.get());
    if(c.choiceID)  delete c.choiceID;
    c.choiceID=0;
    if(js.isMember("choiceID"))
    {
      if(!js["choiceID"].isInt())  return false;
      c.choiceID=new unsigned int();
      c.choiceID[0]=js["choiceID"].asInt();      if(c.choiceID[0]>2000000000)  return false;

    }

    if(c.triggerSource)  delete c.triggerSource;
    c.triggerSource=0;
    if(js.isMember("triggerSource"))
    {
      c.triggerSource=new TriggerSource();
      if(!TriggerSourceMarshaller::fromJSON(js["triggerSource"],c.triggerSource[0]))  return false;
    }

  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}
