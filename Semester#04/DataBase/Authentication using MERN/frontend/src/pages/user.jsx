import React, { useState, useEffect } from "react";
import axios from "axios";
import { useNavigate } from "react-router-dom";
import { jwtDecode } from "jwt-decode"; // Updated import syntax
import "../styles/user.css";

const User = () => {
  const [userData, setUserData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [debugInfo, setDebugInfo] = useState({});
  const navigate = useNavigate();

  useEffect(() => {
    const fetchUserData = async () => {
      const debug = {};
      try {
        const token = localStorage.getItem("token");
        debug.hasToken = !!token;

        if (!token) {
          navigate("/");
          return;
        }

        let decodedToken;
        try {
          // Using the named import jwtDecode
          decodedToken = jwtDecode(token);
          debug.decodedToken = decodedToken;
        } catch (err) {
          console.error("Invalid token", err.message);
          setError("Invalid token format. Please login again.");
          return;
        }

        const userId = decodedToken.userID;
        debug.userId = userId;

        const config = {
          headers: {
            Authorization: `Bearer ${token}`,
          },
        };
        debug.requestConfig = config;

        // Fix the URL to match your server's routes
        const url = `http://localhost:2000/users/${userId}`;
        debug.requestUrl = url;

        debug.apiCallMade = true;
        const response = await axios.get(url, config);
        debug.apiResponse = response.data;

        if (response.data) setUserData(response.data);
        else setError("No user data found");
      } catch (err) {
        console.error("Error fetching user data:", err);
        debug.errorType = err.name;
        debug.errorMessage = err.message;

        if (err.response) {
          debug.responseStatus = err.response.status;
          debug.responseData = err.response.data;
        }

        setError("Failed to load user data. Please try again.");
      } finally {
        setDebugInfo(debug);
        setLoading(false);
      }
    };

    fetchUserData();
  }, [navigate]);

  const handleLogout = () => {
    localStorage.removeItem("token");
    navigate("/");
  };

  if (loading) {
    return (
      <div className="about-container">
        <div className="about-card">
          <h1>Loading...</h1>
        </div>
      </div>
    );
  }

  return (
    <div className="about-container">
      <div className="about-card">
        {error ? (
          <>
            <h1 className="about-title error-title">Error</h1>
            <p className="error-message">{error}</p>
            <div className="debug-section">
              <h3>Debug Information:</h3>
              <pre>{JSON.stringify(debugInfo, null, 2)}</pre>
            </div>
          </>
        ) : userData ? (
          <>
            <h1 className="about-title">User Profile</h1>
            <div className="user-info">
              <div className="info-row">
                <span className="info-label">ID:</span>
                <span className="info-value">{userData.Id || userData.id || "N/A"}</span>
              </div>
              <div className="info-row">
                <span className="info-label">Username:</span>
                <span className="info-value">{userData.Username || userData.username || "N/A"}</span>
              </div>
              <div className="info-row">
                <span className="info-label">Email:</span>
                <span className="info-value">{userData.Email || userData.email || "N/A"}</span>
              </div>
            </div>
          </>
        ) : (
          <h1>No user data available</h1>
        )}

        <button className="logout-button" onClick={handleLogout}>
          {error ? "Back to Login" : "Logout"}
        </button>
      </div>
    </div>
  );
};

export default User;