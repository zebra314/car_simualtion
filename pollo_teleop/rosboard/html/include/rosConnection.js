import { local_ip } from './local_ip.js';

var ros = new ROSLIB.Ros({
  // Change to robot ip address 
  // 9090 is the default port of rosbridge server
  url: 'ws://' + local_ip + ':9090'
});

ros.on('connection', function () {
  document.getElementById("status").innerHTML = "Connected";
});

ros.on('error', function (error) {
  document.getElementById("status").innerHTML = "Error";
});

ros.on('close', function () {
  document.getElementById("status").innerHTML = "Closed";
});

var txt_listener = new ROSLIB.Topic({
  ros: ros,
  name: '/txt_msg',
  messageType: 'std_msgs/String'
});

txt_listener.subscribe(function (m) {
  document.getElementById("msg").innerHTML = m.data;
  move(1, 0);
});

export default ros;
