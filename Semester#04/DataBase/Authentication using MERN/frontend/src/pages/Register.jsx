import React, { useState } from "react";
import axios from "axios";
import { useNavigate, Link } from "react-router-dom";
import "../styles/Login.css"; // Reusing the same CSS file for consistent styling

const Register = () => {
  const [username, setUsername] = useState("");
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [confirmPassword, setConfirmPassword] = useState("");
  const [error, setError] = useState("");
  const navigate = useNavigate();

  const handleRegister = async (e) => {
    e.preventDefault();
    setError("");

    // Basic validation
    if (password !== confirmPassword) {
      setError("Passwords do not match");
      return;
    }

    try {
      const response = await axios.post("http://localhost:2000/auth/register", {
        username,
        email,
        password,
      });

      if (response.status === 201) {
        alert("Registration successful! Please log in.");
        navigate("/"); // Navigate to login page
      }
    } catch (error) {
      if (error.response && error.response.data) {
        setError(error.response.data.error || "Registration failed. Please try again.");
      } else {
        setError("Registration failed. Please try again.");
      }
    }
  };

  return (
    <div className="login-container">
      <div className="login-card">
        <h1 className="login-title">Sign Up</h1>
        {error && <div className="error-message">{error}</div>}
        <form onSubmit={handleRegister}>
          <div className="input-group">
            <label htmlFor="username">👤</label>
            <input
              type="text"
              id="username"
              placeholder="Username"
              className="input-field"
              value={username}
              onChange={(e) => setUsername(e.target.value)}
              required
            />
          </div>
          <div className="input-group">
            <label htmlFor="email">📧</label>
            <input
              type="email"
              id="email"
              placeholder="Email"
              className="input-field"
              value={email}
              onChange={(e) => setEmail(e.target.value)}
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
          <div className="input-group">
            <label htmlFor="confirmPassword">🔒</label>
            <input
              type="password"
              id="confirmPassword"
              placeholder="Confirm Password"
              className="input-field"
              value={confirmPassword}
              onChange={(e) => setConfirmPassword(e.target.value)}
              required
            />
          </div>
          <button type="submit" className="login-button">➡️</button>
        </form>
        <div className="register-link">
          Already have an account? <Link to="/">Login</Link>
        </div>
      </div>
    </div>
  );
};

export default Register;