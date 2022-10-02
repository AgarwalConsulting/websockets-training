#!/usr/bin/env node

// let token = "{someToken}";

let url = `ws://localhost:3000/echo`;
// let url = `ws://localhost:3000/v1/subscribe/`;

let webSocket = new WebSocket(url);

webSocket.onopen = function(e) {
  console.log("[open] Connection established...");
};

// let ackCount = 0;
webSocket.onmessage = function (event) {
  console.log("Received:", event.data);

  // webSocket.send(JSON.stringify("ACK: " + String(ackCount) + " - " + String(event.data)));

  // ackCount++;
}

webSocket.onclose = function(event) {
  if (event.wasClean) {
    console.log(`[close] Connection closed cleanly, code=${event.code} reason=${event.reason}`);
  } else {
    // e.g. server process killed or network down
    // event.code is usually 1006 in this case
    console.log('[close] Connection died');
    // UI: Put your reconnection logic here!
  }
};

webSocket.onerror = function(error) {
  console.log(`[error] ${JSON.stringify(error)} ${error.message}`);
};
