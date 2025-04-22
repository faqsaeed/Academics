import ReactDOM from "react-dom/client";
import { BrowserRouter, Routes, Route } from "react-router-dom";
import About from "./pages/about";
import Login from "./pages/Login";
import User from "./pages/user";
import Register from "./pages/Register";

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/about" element={<About />} />
        <Route path="/" element={<Login />} />
        <Route path="/user" element={<User />} />
        <Route path="/register" element={<Register />} />

        </Routes>
  </BrowserRouter>
  );
}

export default App;