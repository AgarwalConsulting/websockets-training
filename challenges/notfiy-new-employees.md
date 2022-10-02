# Notify connected clients about newly created employees

## Steps

- Take the code in `examples/drogon/emp_server`

- Create a new `WebSocketController`

- Add an end-point: `ws://localhost:3000/v1/subscribe`, which the clients can subscribe using

- Connect a client from the browser, using the code from `examples/browser_js/connect.js`

- When a new employee is created via a POST request:

```bash
curl -X POST http://localhost:3000/v1/employees/ --data '{"name": "Gaurav", "department": "LnD", "projectID": "1001"}'
```

make sure you notify the connected clients from your `WebSocketController`
