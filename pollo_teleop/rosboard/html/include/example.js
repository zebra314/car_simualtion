var ros = new ROSLIB.Ros({
  // Change to robot ip address 
  // 9090 is the default port of rosbridge server
  url: 'ws://192.168.0.153:9090'
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

cmd_vel_listener = new ROSLIB.Topic({
  ros: ros,
  name: "/pollo/cmd_vel",
  messageType: 'geometry_msgs/Twist'
});

move = function (linear, angular) {
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

createJoystick = function () {
  var options = {
    zone: document.getElementById('zone_joystick'),
    threshold: 0.1,
    position: { left: 50 + '%' },
    mode: 'static',
    size: 150,
    color: '#000000',
  };
  manager = nipplejs.create(options);

  linear_speed = 0;
  angular_speed = 0;

  manager.on('start', function (event, nipple) {
    timer = setInterval(function () {
      move(linear_speed, angular_speed);
    }, 25);
  });

  manager.on('move', function (event, nipple) {
    max_linear = 1.7; // m/s
    max_angular = 1.3; // rad/s
    max_distance = 75.0; // pixels;
    linear_speed = Math.sin(nipple.angle.radian) * max_linear * nipple.distance / max_distance;
    angular_speed = -Math.cos(nipple.angle.radian) * max_angular * nipple.distance / max_distance;
  });

  manager.on('end', function () {
    if (timer) {
      clearInterval(timer);
    }
    self.move(0, 0);
  });
}

window.onload = function () {
  createJoystick();
}
