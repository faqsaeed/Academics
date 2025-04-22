import express from "express"
import { getUsers } from "../controllers/userController.js"
import {verifyToken} from "../middlewares/AuthMiddleware.js"

const userRouter = express.Router();

userRouter.get("/:id",verifyToken, getUsers);

export default userRouter;