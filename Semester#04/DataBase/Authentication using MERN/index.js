import express from "express";
import sql from "mssql";
import dbConfig from "./backend/config/dbConfig.js";
import cors from "cors";
import dotenv from "dotenv";

dotenv.config();
const app = express();
app.use(express.json());
app.use(cors());

import authRoutes from "./backend/routes/authRoutes.js";
import userRoutes from "./backend/routes/userRoutes.js";

const PORT = process.env.PORT || 2000;

const testConnection = async () => {
  try 
  {
    await sql.connect(dbConfig);
    console.log("Connected to database successfully!");
  } 
  catch (err) 
  {
    console.error("Database connection failed:", err.message);
  }
};

app.get("/", (req, res) => {
  return res.send("Hello, I am running!");
});

app.use("/users", userRoutes);
app.use("/auth", authRoutes);

app.listen(PORT, async () => {
  console.log(`Server is listening on http://localhost:${PORT}`);
  await testConnection(); 
});