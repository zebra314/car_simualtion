import { local_ip } from './local_ip.js';
import './roslib.js';
import './nipplejs.js';

// Connection
var ros = new ROSLIB.Ros({
  // Change to robot ip address 
  // 9090 is the default port of rosbridge server
  url: 'ws://' + local_ip + ':9090'
});

ros.on('connection', function () {
  // document.getElementById("status").innerHTML = "Connected";
});

ros.on('error', function (error) {
  // document.getElementById("status").innerHTML = "Error";
});

ros.on('close', function () {
  // document.getElementById("status").innerHTML = "Closed";
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

// Joystick control
var cmd_vel_listener = new ROSLIB.Topic({
  ros: ros,
  name: "/pollo/cmd_vel",
  messageType: 'geometry_msgs/Twist'
});

var linear_speed = 0;
var angular_speed = 0;

function move(linear, angular) {
  var twist = new ROSLIB.Message({
    linear: {
      x: linear,
      y: 0,
      z: 0
    },
    angular: {
      x: 0,
      y: 0,
      z: angular
    }
  });
  cmd_vel_listener.publish(twist);
}

function createJoystick() {
  var options = {
    zone: document.getElementById('zone_joystick'),
    threshold: 0.1,
    position: { left: 50 + '%', top: 13 + '%'},
    mode: 'static',
    size: 150,
    color: '#3498db',
  };
  var manager = nipplejs.create(options);

  var timer = null;
  manager.on('start', function (event, nipple) {
    timer = setInterval(function () {
      move(linear_speed, angular_speed);
    }, 25);
  });

  manager.on('move', function (event, nipple) {
    var max_linear = 1.7; // m/s
    var max_angular = 1.3; // rad/s
    var max_distance = 75.0; // pixels;
    linear_speed = Math.sin(nipple.angle.radian) * max_linear * nipple.distance / max_distance;
    angular_speed = -Math.cos(nipple.angle.radian) * max_angular * nipple.distance / max_distance;
  });

  manager.on('end', function () {
    if (timer) {
      clearInterval(timer);
    }
    move(0, 0);
  });
}

function initPage() {
  createJoystick();
}
window.addEventListener('load', initPage);