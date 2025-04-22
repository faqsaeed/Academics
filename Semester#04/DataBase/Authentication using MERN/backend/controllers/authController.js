import bcrypt from "bcryptjs"
import jwt from "jsonwebtoken"
import sql from "mssql"
import dbConfig from "../config/dbConfig.js";


// Secret key for JWT
const JWT_SECRET = process.env.JWT_SECRET; // Change this in production!

// 🔹 Register a new user
export const createUser = async (req, res) => {
    const { username, password, email } = req.body;

    try {
        // Hash password before storing
        const hashedPassword = await bcrypt.hash(password, 10);

        const pool = await sql.connect(dbConfig);
        await pool.request()
            .input("username", sql.VarChar, username)
            .input("password", sql.VarChar, hashedPassword)
            .input("email", sql.VarChar, email)
            .query(`INSERT INTO Users (Username, Email, Password) VALUES (@username, @email, @password)`);

        res.status(201).json({ message: "User registered successfully!" });
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
};

// 🔹 Login a user
export const loginUser = async (req, res) => {
    const { username, password } = req.body;
    try {
      const pool = await sql.connect(dbConfig);
      const result = await pool.request()
        .input("username", sql.VarChar, username)
        .query(`SELECT * FROM Users WHERE Username = @username`);
      
      if (result.recordset.length === 0)
        return res.status(401).json({ error: "Username isn't valid" });
      
      const user = result.recordset[0];
      const isMatch = await bcrypt.compare(password, user.Password);
      
      if (!isMatch)
        return res.status(401).json({ error: "Invalid password" });
      
      // Create JWT token - fixed to use Id instead of UserID
      const token = jwt.sign({ userID: user.Id }, JWT_SECRET, { expiresIn: "1h" });
      
      res.json({ message: "Login successful!", token });
    }
    catch (error) {
      res.status(500).json({ error: error.message });
    }
  };

// 🔹 Logout a user
export const logoutUser = (req, res) => {
    // Invalidate the token on the client side (e.g., remove it from storage)
    res.status(200).json({ message: "Logout successful!" });
};


