var EventEmitter = require('events').EventEmitter
  , fs = require('fs')
  , path = require('path')
  , spawn = require('child_process').spawn;

var CopytoEmmc = function () {

  var Writer = new EventEmitter();
  var baseDirectory = path.join(__dirname, '..', '..', 'linux');
  var installscript = 'copy-to-emmc.sh';

  Writer.install = function() {
    var cmd = path.join(baseDirectory, installscript);
    var args = [];

    var process = spawn(cmd, args);

    process.on('exit', function(code) {
      if (code !==0) {
        console.log('---- Error detected in write-to-emmc process ----');
        Writer.emit("write-to-emmc-failed", "");
      }
      Writer.emit("write-to-emmc-completed", "");
    });

    process.stderr.on('data', function(data) {
      console.log(data.toString());
      Writer.emit("write-to-emmc-error-output", data.toString());
    });

    process.stdout.on('data', function(data) {
      console.log(data.toString());
      Writer.emit("write-to-emmc-output", data.toString());
    });
  }

  return Writer;
}

module.exports = CopytoEmmc;
