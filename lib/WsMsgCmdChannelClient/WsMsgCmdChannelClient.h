#pragma once

#include <MsgCmd.h>

class WsMsgCmdChannelClient
{
public:
  typedef std::function<void(MsgCmd)> MsgCmdCallback;
  WsMsgCmdChannelClient();
};