import React from 'react'
import ReactDOM from 'react-dom/client'

import {
  createBrowserRouter,
  RouterProvider,
  Routes,
  Route,
  Outlet,
} from "react-router-dom";

import ErrorPage from "./ErrorPage";
import RequireAuth from './auth/RequireAuth';
import Auth from './auth/Auth';
import Login from './pages/login/Login';
import Main from "./pages/main/Main"
import Matching from "./pages/matching/Matching"
import GlobalStyle from './GlobalStyle';
import Profile from "./pages/profile/ProfilePage"
import Header from './Header';
import Footer from './Footer';

const BasicLayout = () => {
  return (
    <>
      <Header />
        <Routes>
        <Route path="/main"
          element={
            <RequireAuth>
              <Main />
            </RequireAuth>
          } />
        <Route path="/matching"
          element={
            <RequireAuth>
              <Matching />
            </RequireAuth>
          } />
        <Route path="/profile"
          element={
            <RequireAuth>
              <Profile />
            </RequireAuth >  
          } />
        </Routes>
      <Footer />
    </>
  )
}

const WideLayout = () => {
  return (
    <>
      <Outlet />
    </>
  )
}

const router = createBrowserRouter([
  {
    path: "/",
    element: <Login />,
    errorElement: <ErrorPage />,
  },
  {
    path: "/auth",
    element: <Auth/>,
  },
  {
    path: "/*",
    element: <BasicLayout />,
  }
]);

ReactDOM.createRoot(document.getElementById('root') as HTMLElement).render(
  <React.StrictMode>
    <GlobalStyle/>
    <RouterProvider router={router} />
  </React.StrictMode>
)
