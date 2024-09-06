#include <mavlink.h>
float k=0;
int x;
int a;
int  func () 
{
  int result = 0 ;
  for (int i = 0; i < 8; i++){
    x = analogRead(A0);
    result = result + x; 
  }
  result = result/8;
  return result;
}
void Mav_Request_Data()
{
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];
  const int  maxStreams = 2;
  const uint8_t MAVStreams[maxStreams] = {MAV_DATA_STREAM_EXTENDED_STATUS, MAV_DATA_STREAM_EXTRA1};
  const uint16_t MAVRates[maxStreams] = {0x02,0x05};    
  for (int i=0; i < maxStreams; i++) {
    mavlink_msg_request_data_stream_pack(2, 200, &msg, 1, 0, MAVStreams[i], MAVRates[i], 1);
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
    Serial.write(buf, len);
  }
}
void setup()
{
  Serial.begin(57600);
  pinMode (A0, INPUT);
  mavlink.begin(57600);
}

void loop() 
{ 
a = func ();
  

  int sysid = 1;                
  int compid = 158;               
  int type = MAV_TYPE_QUADROTOR;   
  uint8_t system_type = MAV_TYPE_GENERIC;
  uint8_t autopilot_type = MAV_AUTOPILOT_INVALID; 
  uint8_t system_mode = MAV_MODE_PREFLIGHT; 
  uint32_t custom_mode = 0;
  uint8_t system_state = MAV_STATE_STANDBY;  
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];
  mavlink_msg_heartbeat_pack(1,0, &msg, type, autopilot_type, system_mode, custom_mode, system_state);
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
  unsigned long currentMillisMAVLink = millis();
  if (currentMillisMAVLink - previousMillisMAVLink >= next_interval_MAVLink) 
  {
    previousMillisMAVLink = currentMillisMAVLink;
    Serial.write(buf, len);
    num_hbs_pasados++;
    if(num_hbs_pasados>=num_hbs) {
      Mav_Request_Data();
      num_hbs_pasados=0;
    }
  }
comm_receive();
}
