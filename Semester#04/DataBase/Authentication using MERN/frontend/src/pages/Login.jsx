import React, { useState } from "react";
import axios from "axios";
import { useNavigate, Link } from "react-router-dom";
import "../styles/Login.css";

const Login = () => {
  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState("");
  const navigate = useNavigate();

  const handleLogin = async (e) => {
    e.preventDefault();
    setError("");

    try {
      const response = await axios.post("http://localhost:2000/auth/login", {
        username,
        password,
      });

      const token = response.data.token;
      localStorage.setItem("token", token); // Save JWT in localStorage
      navigate("/user");
    } catch (error) {
      if (error.response && error.response.data) {
        setError(error.response.data.error || "Invalid credentials or server error");
      } else {
        setError("Invalid credentials or server error");
      }
    }
  };

  return (
    <div className="login-container">
      <div className="login-card">
        <h1 className="login-title">Log-In</h1>
        {error && <div className="error-message">{error}</div>}
        <form onSubmit={handleLogin}>
          <div className="input-group">
            <label htmlFor="username">👤</label>
            <input
              type="text"
              id="username"
              placeholder="User Name"
              className="input-field"
              value={username}
              onChange={(e) => setUsername(e.target.value)}
              required
            />
          </div>
          <div className="input-group">
            <label htmlFor="password">🔒</label>
            <input
              type="password"
              id="password"
              placeholder="Password"
              className="input-field"
              value={password}
              onChange={(e) => setPassword(e.target.value)}
              required
            />
          </div>
          <button type="submit" className="login-button">➡️</button>
        </form>
        <div className="register-link">
          Don't have an account? <Link to="/register">Sign Up</Link>
        </div>
      </div>
    </div>
  );
};

export default Login;