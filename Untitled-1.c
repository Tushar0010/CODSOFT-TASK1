{
 "cells": [
  {
   "cell_type": "raw",
   "id": "0c7f4808-794c-415f-a4d8-8b9c8c7ca51a",
   "metadata": {},
   "source": [
    "\n",
    "\n",
    "▶TASK-1 : TITANIC SURVIVAL PREDICTION\n",
    "\n",
    "    Author: TUSHAR\n",
    "\n",
    "    Batch: MAY\n",
    "\n",
    "    Domain: Data Science\n",
    "\n",
    "    Aim: To build a model that predicts whether a passenger on the Titanic survived or not.\n",
    "\n",
    "\n",
    "\n",
    "\n"
   ]
  },
  {
   "cell_type": "raw",
   "id": "eaef0a02-1967-45f2-b118-1a600bb2a8dd",
   "metadata": {},
   "source": [
    "IMPORTING IMPORTANT LIBRARIES"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "id": "b31ab819-4837-4ffd-8314-e3617560c596",
   "metadata": {},
   "outputs": [],
   "source": [
    "import numpy as np\n",
    "import pandas as pd\n",
    "import matplotlib.pyplot as plt\n",
    "import seaborn as sns"
   ]
  },
  {
   "cell_type": "raw",
   "id": "b98f5bea-1231-4b3a-b0ea-a9710257ae58",
   "metadata": {},
   "source": [
    "IMPORTING DATASET"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "id": "539291bd-5d0c-4f85-8376-2d3dc3169d96",
   "metadata": {},
   "outputs": [],
   "source": [
    "df = pd.read_csv(\"tested.csv\")"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 3,
   "id": "bd926066-3a38-425f-a311-fc29ae8b52b7",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>PassengerId</th>\n",
       "      <th>Survived</th>\n",
       "      <th>Pclass</th>\n",
       "      <th>Name</th>\n",
       "      <th>Sex</th>\n",
       "      <th>Age</th>\n",
       "      <th>SibSp</th>\n",
       "      <th>Parch</th>\n",
       "      <th>Ticket</th>\n",
       "      <th>Fare</th>\n",
       "      <th>Cabin</th>\n",
       "      <th>Embarked</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>892</td>\n",
       "      <td>0</td>\n",
       "      <td>3</td>\n",
       "      <td>Kelly, Mr. James</td>\n",
       "      <td>male</td>\n",
       "      <td>34.5</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>330911</td>\n",
       "      <td>7.8292</td>\n",
       "      <td>NaN</td>\n",
       "      <td>Q</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>893</td>\n",
       "      <td>1</td>\n",
       "      <td>3</td>\n",
       "      <td>Wilkes, Mrs. James (Ellen Needs)</td>\n",
       "      <td>female</td>\n",
       "      <td>47.0</td>\n",
       "      <td>1</td>\n",
       "      <td>0</td>\n",
       "      <td>363272</td>\n",
       "      <td>7.0000</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>894</td>\n",
       "      <td>0</td>\n",
       "      <td>2</td>\n",
       "      <td>Myles, Mr. Thomas Francis</td>\n",
       "      <td>male</td>\n",
       "      <td>62.0</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>240276</td>\n",
       "      <td>9.6875</td>\n",
       "      <td>NaN</td>\n",
       "      <td>Q</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>895</td>\n",
       "      <td>0</td>\n",
       "      <td>3</td>\n",
       "      <td>Wirz, Mr. Albert</td>\n",
       "      <td>male</td>\n",
       "      <td>27.0</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>315154</td>\n",
       "      <td>8.6625</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>896</td>\n",
       "      <td>1</td>\n",
       "      <td>3</td>\n",
       "      <td>Hirvonen, Mrs. Alexander (Helga E Lindqvist)</td>\n",
       "      <td>female</td>\n",
       "      <td>22.0</td>\n",
       "      <td>1</td>\n",
       "      <td>1</td>\n",
       "      <td>3101298</td>\n",
       "      <td>12.2875</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "   PassengerId  Survived  Pclass  \\\n",
       "0          892         0       3   \n",
       "1          893         1       3   \n",
       "2          894         0       2   \n",
       "3          895         0       3   \n",
       "4          896         1       3   \n",
       "\n",
       "                                           Name     Sex   Age  SibSp  Parch  \\\n",
       "0                              Kelly, Mr. James    male  34.5      0      0   \n",
       "1              Wilkes, Mrs. James (Ellen Needs)  female  47.0      1      0   \n",
       "2                     Myles, Mr. Thomas Francis    male  62.0      0      0   \n",
       "3                              Wirz, Mr. Albert    male  27.0      0      0   \n",
       "4  Hirvonen, Mrs. Alexander (Helga E Lindqvist)  female  22.0      1      1   \n",
       "\n",
       "    Ticket     Fare Cabin Embarked  \n",
       "0   330911   7.8292   NaN        Q  \n",
       "1   363272   7.0000   NaN        S  \n",
       "2   240276   9.6875   NaN        Q  \n",
       "3   315154   8.6625   NaN        S  \n",
       "4  3101298  12.2875   NaN        S  "
      ]
     },
     "execution_count": 3,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df.head()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "id": "67def7c7-ea86-48e7-91ed-3eeeefee4b67",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>PassengerId</th>\n",
       "      <th>Survived</th>\n",
       "      <th>Pclass</th>\n",
       "      <th>Name</th>\n",
       "      <th>Sex</th>\n",
       "      <th>Age</th>\n",
       "      <th>SibSp</th>\n",
       "      <th>Parch</th>\n",
       "      <th>Ticket</th>\n",
       "      <th>Fare</th>\n",
       "      <th>Cabin</th>\n",
       "      <th>Embarked</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>892</td>\n",
       "      <td>0</td>\n",
       "      <td>3</td>\n",
       "      <td>Kelly, Mr. James</td>\n",
       "      <td>male</td>\n",
       "      <td>34.5</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>330911</td>\n",
       "      <td>7.8292</td>\n",
       "      <td>NaN</td>\n",
       "      <td>Q</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>893</td>\n",
       "      <td>1</td>\n",
       "      <td>3</td>\n",
       "      <td>Wilkes, Mrs. James (Ellen Needs)</td>\n",
       "      <td>female</td>\n",
       "      <td>47.0</td>\n",
       "      <td>1</td>\n",
       "      <td>0</td>\n",
       "      <td>363272</td>\n",
       "      <td>7.0000</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>894</td>\n",
       "      <td>0</td>\n",
       "      <td>2</td>\n",
       "      <td>Myles, Mr. Thomas Francis</td>\n",
       "      <td>male</td>\n",
       "      <td>62.0</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>240276</td>\n",
       "      <td>9.6875</td>\n",
       "      <td>NaN</td>\n",
       "      <td>Q</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>895</td>\n",
       "      <td>0</td>\n",
       "      <td>3</td>\n",
       "      <td>Wirz, Mr. Albert</td>\n",
       "      <td>male</td>\n",
       "      <td>27.0</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>315154</td>\n",
       "      <td>8.6625</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>896</td>\n",
       "      <td>1</td>\n",
       "      <td>3</td>\n",
       "      <td>Hirvonen, Mrs. Alexander (Helga E Lindqvist)</td>\n",
       "      <td>female</td>\n",
       "      <td>22.0</td>\n",
       "      <td>1</td>\n",
       "      <td>1</td>\n",
       "      <td>3101298</td>\n",
       "      <td>12.2875</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>5</th>\n",
       "      <td>897</td>\n",
       "      <td>0</td>\n",
       "      <td>3</td>\n",
       "      <td>Svensson, Mr. Johan Cervin</td>\n",
       "      <td>male</td>\n",
       "      <td>14.0</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>7538</td>\n",
       "      <td>9.2250</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>6</th>\n",
       "      <td>898</td>\n",
       "      <td>1</td>\n",
       "      <td>3</td>\n",
       "      <td>Connolly, Miss. Kate</td>\n",
       "      <td>female</td>\n",
       "      <td>30.0</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>330972</td>\n",
       "      <td>7.6292</td>\n",
       "      <td>NaN</td>\n",
       "      <td>Q</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>7</th>\n",
       "      <td>899</td>\n",
       "      <td>0</td>\n",
       "      <td>2</td>\n",
       "      <td>Caldwell, Mr. Albert Francis</td>\n",
       "      <td>male</td>\n",
       "      <td>26.0</td>\n",
       "      <td>1</td>\n",
       "      <td>1</td>\n",
       "      <td>248738</td>\n",
       "      <td>29.0000</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>8</th>\n",
       "      <td>900</td>\n",
       "      <td>1</td>\n",
       "      <td>3</td>\n",
       "      <td>Abrahim, Mrs. Joseph (Sophie Halaut Easu)</td>\n",
       "      <td>female</td>\n",
       "      <td>18.0</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>2657</td>\n",
       "      <td>7.2292</td>\n",
       "      <td>NaN</td>\n",
       "      <td>C</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>9</th>\n",
       "      <td>901</td>\n",
       "      <td>0</td>\n",
       "      <td>3</td>\n",
       "      <td>Davies, Mr. John Samuel</td>\n",
       "      <td>male</td>\n",
       "      <td>21.0</td>\n",
       "      <td>2</td>\n",
       "      <td>0</td>\n",
       "      <td>A/4 48871</td>\n",
       "      <td>24.1500</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "   PassengerId  Survived  Pclass  \\\n",
       "0          892         0       3   \n",
       "1          893         1       3   \n",
       "2          894         0       2   \n",
       "3          895         0       3   \n",
       "4          896         1       3   \n",
       "5          897         0       3   \n",
       "6          898         1       3   \n",
       "7          899         0       2   \n",
       "8          900         1       3   \n",
       "9          901         0       3   \n",
       "\n",
       "                                           Name     Sex   Age  SibSp  Parch  \\\n",
       "0                              Kelly, Mr. James    male  34.5      0      0   \n",
       "1              Wilkes, Mrs. James (Ellen Needs)  female  47.0      1      0   \n",
       "2                     Myles, Mr. Thomas Francis    male  62.0      0      0   \n",
       "3                              Wirz, Mr. Albert    male  27.0      0      0   \n",
       "4  Hirvonen, Mrs. Alexander (Helga E Lindqvist)  female  22.0      1      1   \n",
       "5                    Svensson, Mr. Johan Cervin    male  14.0      0      0   \n",
       "6                          Connolly, Miss. Kate  female  30.0      0      0   \n",
       "7                  Caldwell, Mr. Albert Francis    male  26.0      1      1   \n",
       "8     Abrahim, Mrs. Joseph (Sophie Halaut Easu)  female  18.0      0      0   \n",
       "9                       Davies, Mr. John Samuel    male  21.0      2      0   \n",
       "\n",
       "      Ticket     Fare Cabin Embarked  \n",
       "0     330911   7.8292   NaN        Q  \n",
       "1     363272   7.0000   NaN        S  \n",
       "2     240276   9.6875   NaN        Q  \n",
       "3     315154   8.6625   NaN        S  \n",
       "4    3101298  12.2875   NaN        S  \n",
       "5       7538   9.2250   NaN        S  \n",
       "6     330972   7.6292   NaN        Q  \n",
       "7     248738  29.0000   NaN        S  \n",
       "8       2657   7.2292   NaN        C  \n",
       "9  A/4 48871  24.1500   NaN        S  "
      ]
     },
     "execution_count": 4,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df.head(10)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "id": "3d8dfe8b-0a32-4d1d-bd50-64e1f15c8526",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "(418, 12)"
      ]
     },
     "execution_count": 6,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df.shape"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 9,
   "id": "50efefdb-3702-4f9f-8987-b7ceb1de2ec6",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>PassengerId</th>\n",
       "      <th>Survived</th>\n",
       "      <th>Pclass</th>\n",
       "      <th>Age</th>\n",
       "      <th>SibSp</th>\n",
       "      <th>Parch</th>\n",
       "      <th>Fare</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>count</th>\n",
       "      <td>418.000000</td>\n",
       "      <td>418.000000</td>\n",
       "      <td>418.000000</td>\n",
       "      <td>332.000000</td>\n",
       "      <td>418.000000</td>\n",
       "      <td>418.000000</td>\n",
       "      <td>417.000000</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>mean</th>\n",
       "      <td>1100.500000</td>\n",
       "      <td>0.363636</td>\n",
       "      <td>2.265550</td>\n",
       "      <td>30.272590</td>\n",
       "      <td>0.447368</td>\n",
       "      <td>0.392344</td>\n",
       "      <td>35.627188</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>std</th>\n",
       "      <td>120.810458</td>\n",
       "      <td>0.481622</td>\n",
       "      <td>0.841838</td>\n",
       "      <td>14.181209</td>\n",
       "      <td>0.896760</td>\n",
       "      <td>0.981429</td>\n",
       "      <td>55.907576</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>min</th>\n",
       "      <td>892.000000</td>\n",
       "      <td>0.000000</td>\n",
       "      <td>1.000000</td>\n",
       "      <td>0.170000</td>\n",
       "      <td>0.000000</td>\n",
       "      <td>0.000000</td>\n",
       "      <td>0.000000</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>25%</th>\n",
       "      <td>996.250000</td>\n",
       "      <td>0.000000</td>\n",
       "      <td>1.000000</td>\n",
       "      <td>21.000000</td>\n",
       "      <td>0.000000</td>\n",
       "      <td>0.000000</td>\n",
       "      <td>7.895800</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>50%</th>\n",
       "      <td>1100.500000</td>\n",
       "      <td>0.000000</td>\n",
       "      <td>3.000000</td>\n",
       "      <td>27.000000</td>\n",
       "      <td>0.000000</td>\n",
       "      <td>0.000000</td>\n",
       "      <td>14.454200</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>75%</th>\n",
       "      <td>1204.750000</td>\n",
       "      <td>1.000000</td>\n",
       "      <td>3.000000</td>\n",
       "      <td>39.000000</td>\n",
       "      <td>1.000000</td>\n",
       "      <td>0.000000</td>\n",
       "      <td>31.500000</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>max</th>\n",
       "      <td>1309.000000</td>\n",
       "      <td>1.000000</td>\n",
       "      <td>3.000000</td>\n",
       "      <td>76.000000</td>\n",
       "      <td>8.000000</td>\n",
       "      <td>9.000000</td>\n",
       "      <td>512.329200</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "       PassengerId    Survived      Pclass         Age       SibSp  \\\n",
       "count   418.000000  418.000000  418.000000  332.000000  418.000000   \n",
       "mean   1100.500000    0.363636    2.265550   30.272590    0.447368   \n",
       "std     120.810458    0.481622    0.841838   14.181209    0.896760   \n",
       "min     892.000000    0.000000    1.000000    0.170000    0.000000   \n",
       "25%     996.250000    0.000000    1.000000   21.000000    0.000000   \n",
       "50%    1100.500000    0.000000    3.000000   27.000000    0.000000   \n",
       "75%    1204.750000    1.000000    3.000000   39.000000    1.000000   \n",
       "max    1309.000000    1.000000    3.000000   76.000000    8.000000   \n",
       "\n",
       "            Parch        Fare  \n",
       "count  418.000000  417.000000  \n",
       "mean     0.392344   35.627188  \n",
       "std      0.981429   55.907576  \n",
       "min      0.000000    0.000000  \n",
       "25%      0.000000    7.895800  \n",
       "50%      0.000000   14.454200  \n",
       "75%      0.000000   31.500000  \n",
       "max      9.000000  512.329200  "
      ]
     },
     "execution_count": 9,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df.describe()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 10,
   "id": "87ac55b6-ee12-47a3-88a0-18ad7e5b0ee9",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "0    266\n",
       "1    152\n",
       "Name: Survived, dtype: int64"
      ]
     },
     "execution_count": 10,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df['Survived'].value_counts()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 11,
   "id": "1c84d126-00b7-43c9-b3b0-c68d9eaa0ad3",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "<AxesSubplot: xlabel='Survived', ylabel='count'>"
      ]
     },
     "execution_count": 11,
     "metadata": {},
     "output_type": "execute_result"
    },
    {
     "data": {
      "image/png": "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TZIkrVq1Sna7XYWFhZoxY4ZX6gAAAF1Xmx49f/TRR/XYY4+purpaZWVlev/9993Lzp07vVbcFVdcoddff1179+6VJH3wwQfaunWrfvazn0k6Ooeourpa6enp7n2sVquGDx+ubdu2nfS4jY2Nqqur81gAAICZ2jSyU1tbq+uvv97btbRy7733yul06sc//rECAgLU0tKixx57TL/4xS8kyf3ou91u99jPbrfryy+/POlx8/Ly9PDDD3dc4QAAwG+0aWTn+uuv18aNG71dSytr167V6tWrVVhYqJ07d2rVqlX6r//6L61atcqj3/G30aSjt7f+ve142dnZcjqd7qWysrJD6gcAAL7XppGd8847Tw888IC2b9+uAQMGKCgoyGP7HXfc4ZXi7rnnHt13332aMmWKJGnAgAH68ssvlZeXp2nTpsnhcEg6OsITGxvr3q+mpqbVaM/xrFarrFarV2oEAAD+rU1hZ+nSpQoLC1NJSYlKSko8tlksFq+FnUOHDqlbN8/Bp4CAAPfTX4mJiXI4HCouLtYll1wiSWpqalJJSYnmz5/vlRoAAEDX1qawU15e7u06Tmj8+PF67LHHlJCQoP79++v999/XwoULddNNN0k6GqwyMzOVm5urpKQkJSUlKTc3V6GhoZo6dWqn1AgAAPxbm9+z0xkWL16sBx54QDNnzlRNTY3i4uI0Y8YMj0fb586dq4aGBs2cOVO1tbUaPHiwNm7cyDt2AACAJMnicrlcZ7rTsZGVk3n22WfbXJAv1NXVyWazyel0KiIiwtfl4CwxdPFQX5fgF96a/ZavSwDQRZ3u/99tfvT8eM3Nzfroo4+0f//+E34gFAAAwFfaFHaKiopatR05ckQzZ85U3759210UAACAt7TpPTsnPFC3brrrrru0aNEibx0SAACg3bwWdiTpiy++0OHDh715SAAAgHZp022srKwsj3WXy6Wqqir99a9/1bRp07xSGAAAgDe0Key8//77HuvdunXTOeecoyeffPIHn9QCAADoTG0KO2+++aa36wAAAOgQ7Xqp4D/+8Q/t2bNHFotF559/vs455xxv1QUAAOAVbZqgXF9fr5tuukmxsbEaNmyYrrzySsXFxenmm2/WoUOHvF0jAABAm7Up7GRlZamkpER//vOftX//fu3fv18vv/yySkpKNGfOHG/XCAAA0GZtuo314osv6k9/+pPS0tLcbT/72c8UEhKiyZMnq6CgwFv1AQAAtEubRnYOHToku93eqj0mJobbWAAAwK+0aWRnyJAheuihh/Tcc88pODhYktTQ0KCHH35YQ4YM8WqBAAB0NXzo9yh/+dBvm8JOfn6+xowZo3PPPVcDBw6UxWJRWVmZrFarNm7c6O0aAQAA2qxNYWfAgAH67LPPtHr1an366adyuVyaMmWKMjIyFBIS4u0aAQAA2qxNYScvL092u1233nqrR/uzzz6rf/zjH7r33nu9UhwAAEB7tWmC8n//93/rxz/+cav2/v3765lnnml3UQAAAN7SprBTXV2t2NjYVu3nnHOOqqqq2l0UAACAt7Qp7MTHx+utt1rPsH7rrbcUFxfX7qIAAAC8pU1zdm655RZlZmaqublZV111lSTp9ddf19y5c3mDMgAA8CttCjtz587Vd999p5kzZ6qpqUmSFBwcrHvvvVfZ2dleLRAAAKA92hR2LBaL5s+frwceeECffPKJQkJClJSUJKvV6u36AAAA2qVNYeeYsLAwXXbZZd6qBQAAwOvaNEEZAACgqyDsAAAAoxF2AACA0Qg7AADAaIQdAABgNMIOAAAwGmEHAAAYjbADAACMRtgBAABGI+wAAACjEXYAAIDR2vVtLKAtKh4Z4OsS/EPPCF9XAABnBUZ2AACA0Qg7AADAaH4fdr7++mv98pe/VHR0tEJDQ3XxxRertLTUvd3lciknJ0dxcXEKCQlRWlqadu/e7cOKAQCAP/HrsFNbW6uhQ4cqKChI//d//6ePP/5YTz75pCIjI919FixYoIULF2rJkiV677335HA4NHr0aB04cMB3hQMAAL/h1xOU58+fr/j4eK1YscLd1qdPH/efXS6X8vPzNW/ePE2aNEmStGrVKtntdhUWFmrGjBmdXTIAAPAzfj2ys379eg0aNEjXX3+9YmJidMkll2jZsmXu7eXl5aqurlZ6erq7zWq1avjw4dq2bdtJj9vY2Ki6ujqPBQAAmMmvw87f/vY3FRQUKCkpSa+++qpuu+023XHHHXruueckSdXV1ZIku93usZ/dbndvO5G8vDzZbDb3Eh8f33EXAQAAfMqvw86RI0d06aWXKjc3V5dccolmzJihW2+9VQUFBR79LBaLx7rL5WrVdrzs7Gw5nU73UllZ2SH1AwAA3/PrsBMbG6sLL7zQo61fv36qqKiQJDkcDklqNYpTU1PTarTneFarVRERER4LAAAwk1+HnaFDh2rPnj0ebXv37lXv3r0lSYmJiXI4HCouLnZvb2pqUklJiVJTUzu1VgAA4J/8+mmsu+66S6mpqcrNzdXkyZP17rvvaunSpVq6dKmko7evMjMzlZubq6SkJCUlJSk3N1ehoaGaOnWqj6sHAAD+wK/DzmWXXaaioiJlZ2frkUceUWJiovLz85WRkeHuM3fuXDU0NGjmzJmqra3V4MGDtXHjRoWHh/uwcgAA4C/8OuxI0rhx4zRu3LiTbrdYLMrJyVFOTk7nFQUAALoMvw87Jkm55zlfl+AXihh0AwB0Ir+eoAwAANBehB0AAGA0wg4AADAaYQcAABiNsAMAAIxG2AEAAEYj7AAAAKMRdgAAgNEIOwAAwGiEHQAAYDTCDgAAMBphBwAAGI2wAwAAjEbYAQAARiPsAAAAoxF2AACA0QJ9XQAAmCDlnud8XYJfKH3iV74uAWiFkR0AAGA0wg4AADAaYQcAABiNsAMAAIxG2AEAAEYj7AAAAKMRdgAAgNEIOwAAwGiEHQAAYDTCDgAAMBphBwAAGI2wAwAAjEbYAQAARiPsAAAAoxF2AACA0Qg7AADAaIQdAABgNMIOAAAwGmEHAAAYjbADAACM1qXCTl5eniwWizIzM91tLpdLOTk5iouLU0hIiNLS0rR7927fFQkAAPxKlwk77733npYuXaqLLrrIo33BggVauHChlixZovfee08Oh0OjR4/WgQMHfFQpAADwJ10i7Bw8eFAZGRlatmyZevbs6W53uVzKz8/XvHnzNGnSJCUnJ2vVqlU6dOiQCgsLT3q8xsZG1dXVeSwAAMBMXSLs3H777Ro7dqxGjRrl0V5eXq7q6mqlp6e726xWq4YPH65t27ad9Hh5eXmy2WzuJT4+vsNqBwAAvuX3YWfNmjXauXOn8vLyWm2rrq6WJNntdo92u93u3nYi2dnZcjqd7qWystK7RQMAAL8R6OsCTqWyslJ33nmnNm7cqODg4JP2s1gsHusul6tV2/GsVqusVqvX6gQAAP7Lr0d2SktLVVNTo5SUFAUGBiowMFAlJSV66qmnFBgY6B7R+fdRnJqamlajPQAA4Ozk12Fn5MiR+vDDD1VWVuZeBg0apIyMDJWVlalv375yOBwqLi5279PU1KSSkhKlpqb6sHIAAOAv/Po2Vnh4uJKTkz3aevTooejoaHd7ZmamcnNzlZSUpKSkJOXm5io0NFRTp071RckAAMDP+HXYOR1z585VQ0ODZs6cqdraWg0ePFgbN25UeHi4r0sDAAB+oMuFnU2bNnmsWywW5eTkKCcnxyf1AAAA/+bXc3YAAADai7ADAACMRtgBAABGI+wAAACjEXYAAIDRCDsAAMBohB0AAGA0wg4AADAaYQcAABiNsAMAAIxG2AEAAEYj7AAAAKMRdgAAgNEIOwAAwGiEHQAAYDTCDgAAMFqgrwsAAJij4pEBvi7BP/SM8HUFOA4jOwAAwGiEHQAAYDTCDgAAMBphBwAAGI2wAwAAjEbYAQAARiPsAAAAoxF2AACA0Qg7AADAaIQdAABgNMIOAAAwGmEHAAAYjbADAACMRtgBAABGI+wAAACjEXYAAIDRCDsAAMBohB0AAGA0wg4AADAaYQcAABjNr8NOXl6eLrvsMoWHhysmJkYTJ07Unj17PPq4XC7l5OQoLi5OISEhSktL0+7du31UMQAA8Dd+HXZKSkp0++23a/v27SouLtbhw4eVnp6u+vp6d58FCxZo4cKFWrJkid577z05HA6NHj1aBw4c8GHlAADAXwT6uoBT2bBhg8f6ihUrFBMTo9LSUg0bNkwul0v5+fmaN2+eJk2aJElatWqV7Ha7CgsLNWPGDF+UDQAA/Ihfj+z8O6fTKUmKioqSJJWXl6u6ulrp6enuPlarVcOHD9e2bdtOepzGxkbV1dV5LAAAwExdJuy4XC5lZWXpiiuuUHJysiSpurpakmS32z362u1297YTycvLk81mcy/x8fEdVzgAAPCpLhN2Zs2apV27dumFF15otc1isXisu1yuVm3Hy87OltPpdC+VlZVerxcAAPgHv56zc8zs2bO1fv16bd68Weeee6673eFwSDo6whMbG+tur6mpaTXaczyr1Sqr1dpxBQMAAL/h1yM7LpdLs2bN0ksvvaQ33nhDiYmJHtsTExPlcDhUXFzsbmtqalJJSYlSU1M7u1wAAOCH/Hpk5/bbb1dhYaFefvllhYeHu+fh2Gw2hYSEyGKxKDMzU7m5uUpKSlJSUpJyc3MVGhqqqVOn+rh6AADgD/w67BQUFEiS0tLSPNpXrFih6dOnS5Lmzp2rhoYGzZw5U7W1tRo8eLA2btyo8PDwTq4WAAD4I78OOy6X6wf7WCwW5eTkKCcnp+MLAgAAXY5fz9kBAABoL8IOAAAwGmEHAAAYjbADAACMRtgBAABGI+wAAACjEXYAAIDRCDsAAMBohB0AAGA0wg4AADAaYQcAABiNsAMAAIxG2AEAAEYj7AAAAKMRdgAAgNEIOwAAwGiEHQAAYDTCDgAAMBphBwAAGI2wAwAAjEbYAQAARiPsAAAAoxF2AACA0Qg7AADAaIQdAABgNMIOAAAwGmEHAAAYjbADAACMRtgBAABGI+wAAACjEXYAAIDRCDsAAMBohB0AAGA0wg4AADAaYQcAABiNsAMAAIxG2AEAAEYzJuw8/fTTSkxMVHBwsFJSUrRlyxZflwQAAPyAEWFn7dq1yszM1Lx58/T+++/ryiuv1JgxY1RRUeHr0gAAgI8ZEXYWLlyom2++Wbfccov69eun/Px8xcfHq6CgwNelAQAAHwv0dQHt1dTUpNLSUt13330e7enp6dq2bdsJ92lsbFRjY6N73el0SpLq6uo6rlBJLY0NHXr8ruJAUIuvS/ALhxsO+7oEv9DRv7vOwu/7KH7fR/H7Pqqjf9/Hju9yuU7Zr8uHnX/+859qaWmR3W73aLfb7aqurj7hPnl5eXr44YdbtcfHx3dIjfCU7OsC4Fds99p8XQK8iN83jtdZv+8DBw7IZjv5ubp82DnGYrF4rLtcrlZtx2RnZysrK8u9fuTIEX333XeKjo4+6T4wR11dneLj41VZWamIiAhflwPAi/h9n11cLpcOHDiguLi4U/br8mGnV69eCggIaDWKU1NT02q05xir1Sqr1erRFhkZ2VElwk9FRETwjyFgKH7fZ49Tjegc0+UnKHfv3l0pKSkqLi72aC8uLlZqaqqPqgIAAP6iy4/sSFJWVpZuvPFGDRo0SEOGDNHSpUtVUVGh2267zdelAQAAHzMi7Nxwww369ttv9cgjj6iqqkrJycl65ZVX1Lt3b1+XBj9ktVr10EMPtbqVCaDr4/eNE7G4fuh5LQAAgC6sy8/ZAQAAOBXCDgAAMBphBwAAGI2wAwAAjEbYwVnl6aefVmJiooKDg5WSkqItW7b4uiQAXrB582aNHz9ecXFxslgsWrduna9Lgh8h7OCssXbtWmVmZmrevHl6//33deWVV2rMmDGqqKjwdWkA2qm+vl4DBw7UkiVLfF0K/BCPnuOsMXjwYF166aUqKChwt/Xr108TJ05UXl6eDysD4E0Wi0VFRUWaOHGir0uBn2BkB2eFpqYmlZaWKj093aM9PT1d27Zt81FVAIDOQNjBWeGf//ynWlpaWn0c1m63t/qILADALIQdnFUsFovHusvlatUGADALYQdnhV69eikgIKDVKE5NTU2r0R4AgFkIOzgrdO/eXSkpKSouLvZoLy4uVmpqqo+qAgB0BiO+eg6cjqysLN14440aNGiQhgwZoqVLl6qiokK33Xabr0sD0E4HDx7U559/7l4vLy9XWVmZoqKilJCQ4MPK4A949BxnlaeffloLFixQVVWVkpOTtWjRIg0bNszXZQFop02bNmnEiBGt2qdNm6aVK1d2fkHwK4QdAABgNObsAAAAoxF2AACA0Qg7AADAaIQdAABgNMIOAAAwGmEHAAAYjbADAACMRtgBAABGI+wAOCts2rRJFotF+/fv79DzTJ8+XRMnTuzQcwA4M4QdAJ2qpqZGM2bMUEJCgqxWqxwOh66++mq9/fbbHXre1NRUVVVVyWazdeh5APgfPgQKoFNde+21am5u1qpVq9S3b1/9/e9/1+uvv67vvvuuTcdzuVxqaWlRYOCp/znr3r27HA5Hm84BoGtjZAdAp9m/f7+2bt2q+fPna8SIEerdu7cuv/xyZWdna+zYsdq3b58sFovKyso89rFYLNq0aZOkf92OevXVVzVo0CBZrVYtX75cFotFn376qcf5Fi5cqD59+sjlcnncxnI6nQoJCdGGDRs8+r/00kvq0aOHDh48KEn6+uuvdcMNN6hnz56Kjo7WhAkTtG/fPnf/lpYWZWVlKTIyUtHR0Zo7d6743CDgfwg7ADpNWFiYwsLCtG7dOjU2NrbrWHPnzlVeXp4++eQTXXfddUpJSdEf/vAHjz6FhYWaOnWqLBaLR7vNZtPYsWNP2H/ChAkKCwvToUOHNGLECIWFhWnz5s3aunWrwsLC9NOf/lRNTU2SpCeffFLPPvusli9frq1bt+q7775TUVFRu64LgPcRdgB0msDAQK1cuVKrVq1SZGSkhg4dqt/85jfatWvXGR/rkUce0ejRo/Uf//Efio6OVkZGhgoLC93b9+7dq9LSUv3yl7884f4ZGRlat26dDh06JEmqq6vTX//6V3f/NWvWqFu3bvqf//kfDRgwQP369dOKFStUUVHhHmXKz89Xdna2rr32WvXr10/PPPMMc4IAP0TYAdCprr32Wn3zzTdav369rr76am3atEmXXnqpVq5ceUbHGTRokMf6lClT9OWXX2r79u2SpD/84Q+6+OKLdeGFF55w/7FjxyowMFDr16+XJL344osKDw9Xenq6JKm0tFSff/65wsPD3SNSUVFR+v777/XFF1/I6XSqqqpKQ4YMcR8zMDCwVV0AfI+wA6DTBQcHa/To0XrwwQe1bds2TZ8+XQ899JC6dTv6T9Lx816am5tPeIwePXp4rMfGxmrEiBHu0Z0XXnjhpKM60tEJy9ddd527f2FhoW644Qb3ROcjR44oJSVFZWVlHsvevXs1derUtl88gE5H2AHgcxdeeKHq6+t1zjnnSJKqqqrc246frPxDMjIytHbtWr399tv64osvNGXKlB/sv2HDBu3evVtvvvmmMjIy3NsuvfRSffbZZ4qJidF5553nsdhsNtlsNsXGxrpHkiTp8OHDKi0tPe16AXQOwg6ATvPtt9/qqquu0urVq7Vr1y6Vl5frj3/8oxYsWKAJEyYoJCREP/nJT/T444/r448/1ubNm3X//fef9vEnTZqkuro6/frXv9aIESP0ox/96JT9hw8fLrvdroyMDPXp00c/+clP3NsyMjLUq1cvTZgwQVu2bFF5eblKSkp055136quvvpIk3XnnnXr88cdVVFSkTz/9VDNnzuzwlxYCOHOEHQCdJiwsTIMHD9aiRYs0bNgwJScn64EHHtCtt96qJUuWSJKeffZZNTc3a9CgQbrzzjv16KOPnvbxIyIiNH78eH3wwQceozQnY7FY9Itf/OKE/UNDQ7V582YlJCRo0qRJ6tevn2666SY1NDQoIiJCkjRnzhz96le/0vTp0zVkyBCFh4fr5z//+Rn8jQDoDBYXL4UAAAAGY2QHAAAYjbADAACMRtgBAABGI+wAAACjEXYAAIDRCDsAAMBohB0AAGA0wg4AADAaYQcAABiNsAMAAIxG2AEAAEb7f0q2ZS+eDl2eAAAAAElFTkSuQmCC\n",
      "text/plain": [
       "<Figure size 640x480 with 1 Axes>"
      ]
     },
     "metadata": {},
     "output_type": "display_data"
    }
   ],
   "source": [
    "#let's visualize the count of survivals wrt pclass\n",
    "sns.countplot(x=df['Survived'], hue=df['Pclass'])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 12,
   "id": "3e494a15-617d-4943-8ac1-7c8d7ea78def",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "0        male\n",
       "1      female\n",
       "2        male\n",
       "3        male\n",
       "4      female\n",
       "        ...  \n",
       "413      male\n",
       "414    female\n",
       "415      male\n",
       "416      male\n",
       "417      male\n",
       "Name: Sex, Length: 418, dtype: object"
      ]
     },
     "execution_count": 12,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df[\"Sex\"]"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 13,
   "id": "6bb44ae9-d44c-4a63-913d-05acf9ef9e1b",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "<AxesSubplot: xlabel='Sex', ylabel='count'>"
      ]
     },
     "execution_count": 13,
     "metadata": {},
     "output_type": "execute_result"
    },
    {
     "data": {
      "image/png": "iVBORw0KGgoAAAANSUhEUgAAAjsAAAGwCAYAAABPSaTdAAAAOXRFWHRTb2Z0d2FyZQBNYXRwbG90bGliIHZlcnNpb24zLjYuMiwgaHR0cHM6Ly9tYXRwbG90bGliLm9yZy8o6BhiAAAACXBIWXMAAA9hAAAPYQGoP6dpAAArRElEQVR4nO3df1xUdb7H8fcIMqL8EpAZSCTcrM1AW7U1uf4AS4hV0/T6O1c3+om5EZqlrUVuK6vd1L35yDbzV5lZt9Laq6tiKWrkptzMX/0wlxa7QZQpiCIQnPtH69ydRFMEZvj6ej4e83g055w58zn0wHk9zpwZbJZlWQIAADBUC08PAAAA0JiIHQAAYDRiBwAAGI3YAQAARiN2AACA0YgdAABgNGIHAAAYzdfTA3iD2tpaffXVVwoMDJTNZvP0OAAA4AJYlqUTJ04oKipKLVqc+/wNsSPpq6++UnR0tKfHAAAA9XDkyBG1b9/+nOuJHUmBgYGSfvhhBQUFeXgaAABwIcrKyhQdHe16HT8XYkdyvXUVFBRE7AAA0Mz81CUoXKAMAACMRuwAAACjETsAAMBoXLMDAICXqKmpUXV1tafH8BotW7aUj4/PJe+H2AEAwMMsy1JxcbGOHz/u6VG8TkhIiJxO5yV9Dx6xAwCAh50JnYiICLVu3ZovuNUPAXjq1CmVlJRIkiIjI+u9L2IHAAAPqqmpcYVOWFiYp8fxKv7+/pKkkpISRURE1PstLS5QBgDAg85co9O6dWsPT+KdzvxcLuVaJmIHAAAvwFtXdWuInwuxAwAAjEbsAAAAoxE7AADgLFu3bpXNZmv0j8NPnDhRQ4cObdTnIHYAAPBiJSUluueee9ShQwfZ7XY5nU6lpKTo/fffb9TnTUhIUFFRkYKDgxv1eZoCHz0HAMCLDR8+XNXV1VqxYoU6duyor7/+Wu+8846+++67eu3PsizV1NTI1/f8CeDn5yen01mv5/A2nNkBAMBLHT9+XDt27NCcOXOUlJSkmJgY/fKXv9T06dM1cOBAffHFF7LZbNqzZ4/bY2w2m7Zu3Srp/9+O2rhxo3r06CG73a4lS5bIZrPpk08+cXu+efPm6corr5RlWW5vY5WWlsrf318bNmxw2/7NN99UmzZtVF5eLkn63//9X40aNUpt27ZVWFiYhgwZoi+++MK1fU1NjTIzMxUSEqKwsDBNmzZNlmU1ys/uX3Fmpwl1f+hFT4+Af8p/6teeHgEAflJAQIACAgK0du1a3XjjjbLb7fXe17Rp0/Qf//Ef6tixo0JCQrR48WK9/PLL+v3vf+/aZtWqVRo7duxZH/cODg7WwIED9fLLL+uWW25x237IkCEKCAjQqVOnlJSUpD59+mjbtm3y9fXVk08+qVtuuUV79+6Vn5+fnn76aS1dulRLlixR586d9fTTT2vNmjXq379/vY/rQnBmBwAAL+Xr66vly5drxYoVCgkJ0b/9279pxowZ2rt370Xva9asWRowYIB+9rOfKSwsTOPGjdOqVatc6z/77DPl5+fr9ttvr/Px48aN09q1a3Xq1ClJUllZmdatW+fafvXq1WrRooVeeOEFxcfH69prr9WyZctUWFjoOsu0YMECTZ8+XcOHD9e1116r5557rkmuCSJ2AADwYsOHD9dXX32lt99+WykpKdq6dau6deum5cuXX9R+evTo4XZ/9OjR+sc//qGdO3dKkl5++WVdf/316ty5c52PHzhwoHx9ffX2229Lkt544w0FBgYqOTlZkpSfn6/PP/9cgYGBrjNSoaGhOn36tA4fPqzS0lIVFRWpV69ern36+vqeNVdjIHYAAPByrVq10oABA/TYY48pLy9PEydO1OOPP64WLX54Gf/X617O9WcV2rRp43Y/MjJSSUlJrrM7r7zyyjnP6kg/XLD87//+767tV61apVGjRrkudK6trVX37t21Z88et9tnn32msWPH1v/gGwCxAwBAM9O5c2edPHlS7dq1kyQVFRW51v3rxco/Zdy4cXr11Vf1/vvv6/Dhwxo9evRPbr9hwwYdOHBAW7Zs0bhx41zrunXrpkOHDikiIkJXXXWV2y04OFjBwcGKjIx0nUmSpO+//175+fkXPG99ETsAAHipo0ePqn///lq5cqX27t2rgoIC/dd//Zfmzp2rIUOGyN/fXzfeeKP++Mc/6uDBg9q2bZt+97vfXfD+hw0bprKyMt13331KSkrSFVdccd7t+/XrJ4fDoXHjxunKK6/UjTfe6Fo3btw4hYeHa8iQIdq+fbsKCgqUm5urBx54QF9++aUk6YEHHtAf//hHrVmzRp988onS09Mb/UsLJWIHAACvFRAQoJ49e2r+/Pnq27ev4uLiNHPmTN11111auHChJGnp0qWqrq5Wjx499MADD+jJJ5+84P0HBQVp8ODB+uijj9zO0pyLzWbTmDFj6ty+devW2rZtmzp06KBhw4bp2muv1R133KGKigoFBQVJkqZMmaJf//rXmjhxonr16qXAwEDddtttF/ETqR+b1RQfcPdyZWVlCg4OVmlpqet/SGPgo+feg4+eA/AWp0+fVkFBgWJjY9WqVStPj+N1zvfzudDXb87sAAAAoxE7AADAaMQOAAAwGrEDAACMRuwAAACjETsAAMBoxA4AADAasQMAAIxG7AAAAKP5evLJs7Oz9eabb+qTTz6Rv7+/EhISNGfOHF1zzTWubSZOnKgVK1a4Pa5nz55uf0issrJSU6dO1SuvvKKKigrddNNNevbZZ9W+ffsmOxYAAJpKU38jf32/df7ZZ5/VU089paKiIl133XVasGCB+vTp08DT/TSPntnJzc3VpEmTtHPnTuXk5Oj7779XcnKyTp486bbdLbfcoqKiItdt/fr1buszMjK0Zs0arV69Wjt27FB5ebkGDRqkmpqapjwcAADwT6+++qoyMjL06KOP6sMPP1SfPn2UmpqqwsLCJp/Fo2d2NmzY4HZ/2bJlioiIUH5+vvr27etabrfb5XQ669xHaWmplixZopdeekk333yzJGnlypWKjo7W5s2blZKS0ngHAAAA6jRv3jylpaXpzjvvlCQtWLBAGzdu1KJFi5Sdnd2ks3jVNTulpaWSpNDQULflW7duVUREhK6++mrdddddKikpca3Lz89XdXW1kpOTXcuioqIUFxenvLy8Op+nsrJSZWVlbjcAANAwqqqqlJ+f7/baLEnJycnnfG1uTF4TO5ZlKTMzU71791ZcXJxreWpqql5++WW9++67evrpp7Vr1y71799flZWVkqTi4mL5+fmpbdu2bvtzOBwqLi6u87mys7MVHBzsukVHRzfegQEAcJn59ttvVVNTI4fD4bb8fK/Njcmjb2P9q/vvv1979+7Vjh073JaPGjXK9d9xcXHq0aOHYmJitG7dOg0bNuyc+7MsSzabrc5106dPV2Zmput+WVkZwQMAQAP78evw+V6bG5NXnNmZPHmy3n77bW3ZsuUnP0EVGRmpmJgYHTp0SJLkdDpVVVWlY8eOuW1XUlJyVlGeYbfbFRQU5HYDAAANIzw8XD4+PmedxTnfa3Nj8mjsWJal+++/X2+++abeffddxcbG/uRjjh49qiNHjigyMlKS1L17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8MMPX9KTl5eX6/PPP3fdLygo0J49exQaGqrQ0FBlZWVp+PDhioyM1BdffKEZM2YoPDxct912myQpODhYaWlpmjJlisLCwhQaGqqpU6cqPj7e9eksAABweatX7Bw7dkwjRoy45CffvXu3kpKSXPfPXDQ8YcIELVq0SPv27dOLL76o48ePKzIyUklJSXr11VcVGBjoesz8+fPl6+urkSNHqqKiQjfddJOWL1/Od+wAAABJ9YydESNGaNOmTbr33nsv6ckTExNlWdY512/cuPEn99GqVSs988wzDf6RdwAAYIZ6xc5VV12lmTNnaufOnYqPj1fLli3d1v/2t79tkOEAAAAuVb1i5/nnn1dAQIByc3OVm5vrts5msxE7AADAa9QrdgoKChp6DgAAgEZRr796DgAA0FzU68zOHXfccd71S5curdcwAAAADa3eHz3/V9XV1dq/f7+OHz9e5x8IBQAA8JR6xc6aNWvOWlZbW6v09HR17NjxkocCAABoKA12zU6LFi304IMPav78+Q21SwAAgEvWoBcoHz58WN9//31D7hIAAOCS1OttrDN/1uEMy7JUVFSkdevWacKECQ0yGAAAQEOoV+x8+OGHbvdbtGihdu3a6emnn/7JT2oBAAA0pXrFzpYtWxp6DgAAgEZRr9g545tvvtGnn34qm82mq6++Wu3atWuouQAAABpEvS5QPnnypO644w5FRkaqb9++6tOnj6KiopSWlqZTp0419IwAAAD1Vq/YyczMVG5urv7yl7/o+PHjOn78uN566y3l5uZqypQpDT0jAABAvdXrbaw33nhDr7/+uhITE13LfvWrX8nf318jR47UokWLGmo+AACAS1KvMzunTp2Sw+E4a3lERARvYwEAAK9Sr9jp1auXHn/8cZ0+fdq1rKKiQk888YR69erVYMMBAABcqnq9jbVgwQKlpqaqffv26tq1q2w2m/bs2SO73a5NmzY19IwAAAD1Vq/YiY+P16FDh7Ry5Up98sknsixLo0eP1rhx4+Tv79/QMwIAANRbvWInOztbDodDd911l9vypUuX6ptvvtHDDz/cIMMBAABcqnpds/PnP/9ZP//5z89aft111+m555675KEAAAAaSr1ip7i4WJGRkWctb9eunYqKii55KAAAgIZSr9iJjo7We++9d9by9957T1FRUZc8FAAAQEOp1zU7d955pzIy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oZ4eA7gsWJalu+++W6GhobLZbNqzZ49H5vjiiy88+vxoGkZ8GgsA0Lxs2LBBy5cv19atW9WxY0eFh4d7eiQYjNgBADS5w4cPKzIyki9/RZPgbSw0S4mJiZo8ebIyMjLUtm1bORwOPf/88zp58qR+85vfKDAwUD/72c/017/+VZJUU1OjtLQ0xcbGyt/fX9dcc43+9Kc/nfc5LMvS3Llz1bFjR/n7+6tr1656/fXXm+LwAKNNnDhRkydPVmFhoWw2m6688sqf/H3bunWrbDabNm7cqF/84hfy9/dX//79VVJSor/+9a+69tprFRQUpDFjxujUqVOux23YsEG9e/dWSEiIwsLCNGjQIB0+fPi88x08eFC/+tWvFBAQIIfDofHjx+vbb79ttJ8HGh+xg2ZrxYoVCg8P1wcffKDJkyfrvvvu04gRI5SQkKD/+Z//UUpKisaPH69Tp06ptrZW7du312uvvaaDBw/qscce04wZM/Taa6+dc/+/+93vtGzZMi1atEgHDhzQgw8+qNtvv125ublNeJSAef70pz9p1qxZat++vYqKirRr164L/n3LysrSwoULlZeXpyNHjmjkyJFasGCBVq1apXXr1iknJ0fPPPOMa/uTJ08qMzNTu3bt0jvvvKMWLVrotttuU21tbZ2zFRUVqV+/frr++uu1e/dubdiwQV9//bVGjhzZqD8TNDILaIb69etn9e7d23X/+++/t9q0aWONHz/etayoqMiSZL3//vt17iM9Pd0aPny46/6ECROsIUOGWJZlWeXl5VarVq2svLw8t8ekpaVZY8aMacAjAS5P8+fPt2JiYizLurDfty1btliSrM2bN7vWZ2dnW5Ksw4cPu5bdc889VkpKyjmft6SkxJJk7du3z7IsyyooKLAkWR9++KFlWZY1c+ZMKzk52e0xR44csSRZn376ab2PF57FNTtotrp06eL6bx8fH4WFhSk+Pt617MxfvS8pKZEkPffcc3rhhRf0j3/8QxUVFaqqqtL1119f574PHjyo06dPa8CAAW7Lq6qq9Itf/KKBjwS4vF3M79u//t47HA61bt1aHTt2dFv2wQcfuO4fPnxYM2fO1M6dO/Xtt9+6zugUFhYqLi7urFny8/O1ZcsWBQQEnLXu8OHDuvrqq+t3kPAoYgfNVsuWLd3u22w2t2U2m02SVFtbq9dee00PPvignn76afXq1UuBgYF66qmn9Le//a3OfZ/5B3HdunW64oor3NbxN3eAhnUxv28//h2v69+Bf32LavDgwYqOjtbixYsVFRWl2tpaxcXFqaqq6pyzDB48WHPmzDlrXWRk5MUdGLwGsYPLwvbt25WQkKD09HTXsvNdpNi5c2fZ7XYVFhaqX79+TTEicNlqrN+3o0eP6uOPP9af//xn9enTR5K0Y8eO8z6mW7dueuONN3TllVfK15eXSFPwfxKXhauuukovvviiNm7cqNjYWL300kvatWuXYmNj69w+MDBQU6dO1YMPPqja2lr17t1bZWVlysvLU0BAgCZMmNDERwCYq7F+39q2bauwsDA9//zzioyMVGFhoR555JHzPmbSpElavHixxowZo4ceekjh4eH6/PPPtXr1ai1evFg+Pj71mgWeRezgsnDvvfdqz549GjVqlGw2m8aMGaP09HTXR9Pr8vvf/14RERHKzs7W3//+d4WEhKhbt26aMWNGE04OXB4a4/etRYsWWr16tX77298qLi5O11xzjf7zP/9TiYmJ53xMVFSU3nvvPT388MNKSUlRZWWlYmJidMstt6hFCz7A3FzZLMuyPD0EAABAYyFTAQCA0YgdAABgNGIHAAAYjdgBAABGI3YAAIDRiB0AAGA0YgcAABiN2AEAAEYjdgAAgNGIHQDNUklJie655x516NBBdrtdTqdTKSkpev/99z09GgAvw9/GAtAsDR8+XNXV1VqxYoU6duyor7/+Wu+8846+++47T48GwMtwZgdAs3P8+HHt2LFDc+bMUVJSkmJiYvTLX/5S06dP18CBAyVJpaWluvvuuxUREaGgoCD1799fH330kSTpm2++kdPp1OzZs137/Nvf/iY/Pz9t2rTJI8cEoPEQOwCanYCAAAUEBGjt2rWqrKw8a71lWRo4cKCKi4u1fv165efnq1u3brrpppv03XffqV27dlq6dKmysrK0e/dulZeX6/bbb1d6erqSk5M9cEQAGhN/9RxAs/TGG2/orrvuUkVFhbp166Z+/fpp9OjR6tKli959913ddtttKikpkd1udz3mqquu0rRp03T33XdLkiZNmqTNmzfrhhtu0EcffaRdu3apVatWnjokAI2E2AHQbJ0+fVrbt2/X+++/rw0bNuiDDz7QCy+8oG+++UaPPPKI/P393bavqKjQ1KlTNWfOHNf9uLg4HTlyRLt371aXLl08cRgAGhmxA8AYd955p3JycpSenq5nnnlGW7duPWubkJAQhYeHS5IOHDigHj16qLq6WmvWrNHgwYObeGIATYFPYwEwRufOnbV27Vp169ZNxcXF8vX11ZVXXlnntlVVVRo3bpxGjRqln//850pLS9O+ffvkcDiadmgAjY4zOwCanaNHj2rEiBG644471KVLFwUGBmr37t2aPHmyBg4cqBdeeEF9+/bViRMnNGfOHF1zzTX66quvtH79eg0dOlQ9evTQQw89pNdff10fffSRAgIClJSUpMDAQP33f/+3pw8PQAMjdgA0O5WVlcrKytKmTZt0+PBhVVdXKzo6WiNGjNCMGTPk7++vEydO6NFHH9Ubb7zh+qh53759lZ2drcOHD2vAgAHasmWLevfuLUkqLCxUly5dlJ2drfvuu8/DRwigIRE7AADAaHzPDgAAMBqxAwAAjEbsAAAAoxE7AADAaMQOAAAwGrEDAACMRuwAAACjETsAAMBoxA4AADAasQMAAIxG7AAAAKP9H0KOlCjvPnqQAAAAAElFTkSuQmCC\n",
      "text/plain": [
       "<Figure size 640x480 with 1 Axes>"
      ]
     },
     "metadata": {},
     "output_type": "display_data"
    }
   ],
   "source": [
    "#let's visualize the count of survivals wrt Gender\n",
    "sns.countplot(x=df['Sex'], hue=df['Survived'])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 14,
   "id": "0fc48d62-2d08-45ad-b6a7-a14fa8fd08fe",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>Survived</th>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>Sex</th>\n",
       "      <th></th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>female</th>\n",
       "      <td>1.0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>male</th>\n",
       "      <td>0.0</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "        Survived\n",
       "Sex             \n",
       "female       1.0\n",
       "male         0.0"
      ]
     },
     "execution_count": 14,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "#Look at survival rate by sex\n",
    "df.groupby('Sex')[['Survived']].mean()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 15,
   "id": "e2bdc852-bedf-476a-9ba4-731c88fb7e2f",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "array(['male', 'female'], dtype=object)"
      ]
     },
     "execution_count": 15,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df['Sex'].unique()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 16,
   "id": "228f8785-2654-481b-980e-8e5a8f910ff9",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>PassengerId</th>\n",
       "      <th>Survived</th>\n",
       "      <th>Pclass</th>\n",
       "      <th>Name</th>\n",
       "      <th>Sex</th>\n",
       "      <th>Age</th>\n",
       "      <th>SibSp</th>\n",
       "      <th>Parch</th>\n",
       "      <th>Ticket</th>\n",
       "      <th>Fare</th>\n",
       "      <th>Cabin</th>\n",
       "      <th>Embarked</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>892</td>\n",
       "      <td>0</td>\n",
       "      <td>3</td>\n",
       "      <td>Kelly, Mr. James</td>\n",
       "      <td>1</td>\n",
       "      <td>34.5</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>330911</td>\n",
       "      <td>7.8292</td>\n",
       "      <td>NaN</td>\n",
       "      <td>Q</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>893</td>\n",
       "      <td>1</td>\n",
       "      <td>3</td>\n",
       "      <td>Wilkes, Mrs. James (Ellen Needs)</td>\n",
       "      <td>0</td>\n",
       "      <td>47.0</td>\n",
       "      <td>1</td>\n",
       "      <td>0</td>\n",
       "      <td>363272</td>\n",
       "      <td>7.0000</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>894</td>\n",
       "      <td>0</td>\n",
       "      <td>2</td>\n",
       "      <td>Myles, Mr. Thomas Francis</td>\n",
       "      <td>1</td>\n",
       "      <td>62.0</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>240276</td>\n",
       "      <td>9.6875</td>\n",
       "      <td>NaN</td>\n",
       "      <td>Q</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>895</td>\n",
       "      <td>0</td>\n",
       "      <td>3</td>\n",
       "      <td>Wirz, Mr. Albert</td>\n",
       "      <td>1</td>\n",
       "      <td>27.0</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>315154</td>\n",
       "      <td>8.6625</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>896</td>\n",
       "      <td>1</td>\n",
       "      <td>3</td>\n",
       "      <td>Hirvonen, Mrs. Alexander (Helga E Lindqvist)</td>\n",
       "      <td>0</td>\n",
       "      <td>22.0</td>\n",
       "      <td>1</td>\n",
       "      <td>1</td>\n",
       "      <td>3101298</td>\n",
       "      <td>12.2875</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "   PassengerId  Survived  Pclass  \\\n",
       "0          892         0       3   \n",
       "1          893         1       3   \n",
       "2          894         0       2   \n",
       "3          895         0       3   \n",
       "4          896         1       3   \n",
       "\n",
       "                                           Name  Sex   Age  SibSp  Parch  \\\n",
       "0                              Kelly, Mr. James    1  34.5      0      0   \n",
       "1              Wilkes, Mrs. James (Ellen Needs)    0  47.0      1      0   \n",
       "2                     Myles, Mr. Thomas Francis    1  62.0      0      0   \n",
       "3                              Wirz, Mr. Albert    1  27.0      0      0   \n",
       "4  Hirvonen, Mrs. Alexander (Helga E Lindqvist)    0  22.0      1      1   \n",
       "\n",
       "    Ticket     Fare Cabin Embarked  \n",
       "0   330911   7.8292   NaN        Q  \n",
       "1   363272   7.0000   NaN        S  \n",
       "2   240276   9.6875   NaN        Q  \n",
       "3   315154   8.6625   NaN        S  \n",
       "4  3101298  12.2875   NaN        S  "
      ]
     },
     "execution_count": 16,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "from sklearn.preprocessing import LabelEncoder\n",
    "labelencoder = LabelEncoder()\n",
    "\n",
    "df['Sex']= labelencoder.fit_transform(df['Sex'])\n",
    "\n",
    "df.head()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 17,
   "id": "a5c229ea-f2fe-4f78-9458-90317bd6ea7c",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "(0      1\n",
       " 1      0\n",
       " 2      1\n",
       " 3      1\n",
       " 4      0\n",
       "       ..\n",
       " 413    1\n",
       " 414    0\n",
       " 415    1\n",
       " 416    1\n",
       " 417    1\n",
       " Name: Sex, Length: 418, dtype: int64,\n",
       " 0      0\n",
       " 1      1\n",
       " 2      0\n",
       " 3      0\n",
       " 4      1\n",
       "       ..\n",
       " 413    0\n",
       " 414    1\n",
       " 415    0\n",
       " 416    0\n",
       " 417    0\n",
       " Name: Survived, Length: 418, dtype: int64)"
      ]
     },
     "execution_count": 17,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df['Sex'], df['Survived']"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 18,
   "id": "5b8cf276-5bb3-4340-a56f-c4613f44ca26",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "<AxesSubplot: xlabel='Sex', ylabel='count'>"
      ]
     },
     "execution_count": 18,
     "metadata": {},
     "output_type": "execute_result"
    },
    {
     "data": {
      "image/png": "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f/6a7z8qKkqjR4/WJ5984nWU5kpsNpt+8pOfXHZ9165dtX37dvXo0UNjx45V79699cADD6ihoUFRUVGSpNmzZ+tnP/uZpk2bpgEDBigyMlL33Xffd/iJ+MZmtccH3IOc2+1WdHS06urqPP9BAOC74KPnwaOjffT8woULqqysVFpamrp06RLocYLO1X4+1/r6zZEdAABgNGIHAAAYjdgBAABGI3YAAIDRiB0AAGA0YgcAABiN2AEAAEYjdgAAgNGIHQAAYLTQQD54cXGx3n77bX366acKDw9Xdna2FixYoB/84AeeNdOmTdPq1au9btevXz+vXyTW2NioOXPm6M0331RDQ4OGDRumZcuW6aabbmq35wIAQHtp72/s9vVbqZctW6YXXnhB1dXVuu2227RkyRINHDjQz9N9u4Ae2SkvL9fMmTO1e/dulZWV6csvv1Rubq7OnTvnte6uu+5SdXW157Jp0yav/fn5+SotLdW6deu0c+dO1dfX6+6771ZLS0t7Ph0AAPC19evXKz8/X/PmzdPHH3+sgQMHKi8vT1VVVe0+S0CP7GzevNnr+qpVq5SYmKiKigoNGjTIs91ut8vpdF72Purq6rRixQq9/vrrGj58uCRpzZo1SklJ0fvvv6+RI0e23RMAAACXtWjRIk2fPl0PPvigJGnJkiV67733tHz5chUXF7frLEF1zk5dXZ0kKTY21mv7tm3blJiYqO9///t66KGHVFNT49lXUVGh5uZm5ebmerYlJycrPT1du3btuuzjNDY2yu12e10AAIB/NDU1qaKiwuu1WZJyc3Ov+NrcloImdizLUkFBge68806lp6d7tufl5emNN97Qhx9+qBdffFF79uzR0KFD1djYKElyuVwKCwtT9+7dve7P4XDI5XJd9rGKi4sVHR3tuaSkpLTdEwMA4AbzxRdfqKWlRQ6Hw2v71V6b21JA38b6W4899pj279+vnTt3em2fOHGi58/p6enKyspSamqqNm7cqLFjx17x/izLks1mu+y+wsJCFRQUeK673W6CBwAAP/vm6/DVXpvbUlAc2Zk1a5beffddbd269Vs/QZWUlKTU1FQdPnxYkuR0OtXU1KQzZ854raupqWlVlJfY7XZFRUV5XQAAgH/Ex8crJCSk1VGcq702t6WAxo5lWXrsscf09ttv68MPP1RaWtq33ubUqVM6duyYkpKS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\n",
      "text/plain": [
       "<Figure size 640x480 with 1 Axes>"
      ]
     },
     "metadata": {},
     "output_type": "display_data"
    }
   ],
   "source": [
    "sns.countplot(x=df['Sex'], hue=df[\"Survived\"])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 19,
   "id": "0ed899a2-1da6-49c7-bb93-92f6978000a3",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "PassengerId      0\n",
       "Survived         0\n",
       "Pclass           0\n",
       "Name             0\n",
       "Sex              0\n",
       "Age             86\n",
       "SibSp            0\n",
       "Parch            0\n",
       "Ticket           0\n",
       "Fare             1\n",
       "Cabin          327\n",
       "Embarked         0\n",
       "dtype: int64"
      ]
     },
     "execution_count": 19,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df.isna().sum()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 20,
   "id": "355059df-5520-4298-888e-02b37a28526b",
   "metadata": {},
   "outputs": [],
   "source": [
    "# After dropping non required column\n",
    "df=df.drop(['Age'], axis=1)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 21,
   "id": "261a4319-8b26-411d-a7e2-46fc352d32c0",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>PassengerId</th>\n",
       "      <th>Survived</th>\n",
       "      <th>Pclass</th>\n",
       "      <th>Name</th>\n",
       "      <th>Sex</th>\n",
       "      <th>SibSp</th>\n",
       "      <th>Parch</th>\n",
       "      <th>Ticket</th>\n",
       "      <th>Fare</th>\n",
       "      <th>Cabin</th>\n",
       "      <th>Embarked</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>892</td>\n",
       "      <td>0</td>\n",
       "      <td>3</td>\n",
       "      <td>Kelly, Mr. James</td>\n",
       "      <td>1</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>330911</td>\n",
       "      <td>7.8292</td>\n",
       "      <td>NaN</td>\n",
       "      <td>Q</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>893</td>\n",
       "      <td>1</td>\n",
       "      <td>3</td>\n",
       "      <td>Wilkes, Mrs. James (Ellen Needs)</td>\n",
       "      <td>0</td>\n",
       "      <td>1</td>\n",
       "      <td>0</td>\n",
       "      <td>363272</td>\n",
       "      <td>7.0000</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>894</td>\n",
       "      <td>0</td>\n",
       "      <td>2</td>\n",
       "      <td>Myles, Mr. Thomas Francis</td>\n",
       "      <td>1</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>240276</td>\n",
       "      <td>9.6875</td>\n",
       "      <td>NaN</td>\n",
       "      <td>Q</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>895</td>\n",
       "      <td>0</td>\n",
       "      <td>3</td>\n",
       "      <td>Wirz, Mr. Albert</td>\n",
       "      <td>1</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>315154</td>\n",
       "      <td>8.6625</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>896</td>\n",
       "      <td>1</td>\n",
       "      <td>3</td>\n",
       "      <td>Hirvonen, Mrs. Alexander (Helga E Lindqvist)</td>\n",
       "      <td>0</td>\n",
       "      <td>1</td>\n",
       "      <td>1</td>\n",
       "      <td>3101298</td>\n",
       "      <td>12.2875</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>5</th>\n",
       "      <td>897</td>\n",
       "      <td>0</td>\n",
       "      <td>3</td>\n",
       "      <td>Svensson, Mr. Johan Cervin</td>\n",
       "      <td>1</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>7538</td>\n",
       "      <td>9.2250</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>6</th>\n",
       "      <td>898</td>\n",
       "      <td>1</td>\n",
       "      <td>3</td>\n",
       "      <td>Connolly, Miss. Kate</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>330972</td>\n",
       "      <td>7.6292</td>\n",
       "      <td>NaN</td>\n",
       "      <td>Q</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>7</th>\n",
       "      <td>899</td>\n",
       "      <td>0</td>\n",
       "      <td>2</td>\n",
       "      <td>Caldwell, Mr. Albert Francis</td>\n",
       "      <td>1</td>\n",
       "      <td>1</td>\n",
       "      <td>1</td>\n",
       "      <td>248738</td>\n",
       "      <td>29.0000</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>8</th>\n",
       "      <td>900</td>\n",
       "      <td>1</td>\n",
       "      <td>3</td>\n",
       "      <td>Abrahim, Mrs. Joseph (Sophie Halaut Easu)</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>0</td>\n",
       "      <td>2657</td>\n",
       "      <td>7.2292</td>\n",
       "      <td>NaN</td>\n",
       "      <td>C</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>9</th>\n",
       "      <td>901</td>\n",
       "      <td>0</td>\n",
       "      <td>3</td>\n",
       "      <td>Davies, Mr. John Samuel</td>\n",
       "      <td>1</td>\n",
       "      <td>2</td>\n",
       "      <td>0</td>\n",
       "      <td>A/4 48871</td>\n",
       "      <td>24.1500</td>\n",
       "      <td>NaN</td>\n",
       "      <td>S</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "   PassengerId  Survived  Pclass  \\\n",
       "0          892         0       3   \n",
       "1          893         1       3   \n",
       "2          894         0       2   \n",
       "3          895         0       3   \n",
       "4          896         1       3   \n",
       "5          897         0       3   \n",
       "6          898         1       3   \n",
       "7          899         0       2   \n",
       "8          900         1       3   \n",
       "9          901         0       3   \n",
       "\n",
       "                                           Name  Sex  SibSp  Parch     Ticket  \\\n",
       "0                              Kelly, Mr. James    1      0      0     330911   \n",
       "1              Wilkes, Mrs. James (Ellen Needs)    0      1      0     363272   \n",
       "2                     Myles, Mr. Thomas Francis    1      0      0     240276   \n",
       "3                              Wirz, Mr. Albert    1      0      0     315154   \n",
       "4  Hirvonen, Mrs. Alexander (Helga E Lindqvist)    0      1      1    3101298   \n",
       "5                    Svensson, Mr. Johan Cervin    1      0      0       7538   \n",
       "6                          Connolly, Miss. Kate    0      0      0     330972   \n",
       "7                  Caldwell, Mr. Albert Francis    1      1      1     248738   \n",
       "8     Abrahim, Mrs. Joseph (Sophie Halaut Easu)    0      0      0       2657   \n",
       "9                       Davies, Mr. John Samuel    1      2      0  A/4 48871   \n",
       "\n",
       "      Fare Cabin Embarked  \n",
       "0   7.8292   NaN        Q  \n",
       "1   7.0000   NaN        S  \n",
       "2   9.6875   NaN        Q  \n",
       "3   8.6625   NaN        S  \n",
       "4  12.2875   NaN        S  \n",
       "5   9.2250   NaN        S  \n",
       "6   7.6292   NaN        Q  \n",
       "7  29.0000   NaN        S  \n",
       "8   7.2292   NaN        C  \n",
       "9  24.1500   NaN        S  "
      ]
     },
     "execution_count": 21,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "df_final = df\n",
    "df_final.head(10)"
   ]
  },
  {
   "cell_type": "raw",
   "id": "79990176-bd8d-4ab4-a073-b87051d76446",
   "metadata": {},
   "source": [
    "MODEL TRAINING"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 22,
   "id": "348a81c8-e345-42a3-848c-d5ae7dcc5719",
   "metadata": {},
   "outputs": [],
   "source": [
    "X= df[['Pclass', 'Sex']]\n",
    "Y=df['Survived']"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 23,
   "id": "c8fbb0db-5546-4cb4-b799-38451a5687d6",
   "metadata": {},
   "outputs": [],
   "source": [
    "from sklearn.model_selection import train_test_split\n",
    "X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size = 0.2, random_state = 0)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 25,
   "id": "39a35b59-1450-4b07-b1dd-732f8f2fbac1",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/html": [
       "<style>#sk-container-id-2 {color: black;background-color: white;}#sk-container-id-2 pre{padding: 0;}#sk-container-id-2 div.sk-toggleable {background-color: white;}#sk-container-id-2 label.sk-toggleable__label {cursor: pointer;display: block;width: 100%;margin-bottom: 0;padding: 0.3em;box-sizing: border-box;text-align: center;}#sk-container-id-2 label.sk-toggleable__label-arrow:before {content: \"▸\";float: left;margin-right: 0.25em;color: #696969;}#sk-container-id-2 label.sk-toggleable__label-arrow:hover:before {color: black;}#sk-container-id-2 div.sk-estimator:hover label.sk-toggleable__label-arrow:before {color: black;}#sk-container-id-2 div.sk-toggleable__content {max-height: 0;max-width: 0;overflow: hidden;text-align: left;background-color: #f0f8ff;}#sk-container-id-2 div.sk-toggleable__content pre {margin: 0.2em;color: black;border-radius: 0.25em;background-color: #f0f8ff;}#sk-container-id-2 input.sk-toggleable__control:checked~div.sk-toggleable__content {max-height: 200px;max-width: 100%;overflow: auto;}#sk-container-id-2 input.sk-toggleable__control:checked~label.sk-toggleable__label-arrow:before {content: \"▾\";}#sk-container-id-2 div.sk-estimator input.sk-toggleable__control:checked~label.sk-toggleable__label {background-color: #d4ebff;}#sk-container-id-2 div.sk-label input.sk-toggleable__control:checked~label.sk-toggleable__label {background-color: #d4ebff;}#sk-container-id-2 input.sk-hidden--visually {border: 0;clip: rect(1px 1px 1px 1px);clip: rect(1px, 1px, 1px, 1px);height: 1px;margin: -1px;overflow: hidden;padding: 0;position: absolute;width: 1px;}#sk-container-id-2 div.sk-estimator {font-family: monospace;background-color: #f0f8ff;border: 1px dotted black;border-radius: 0.25em;box-sizing: border-box;margin-bottom: 0.5em;}#sk-container-id-2 div.sk-estimator:hover {background-color: #d4ebff;}#sk-container-id-2 div.sk-parallel-item::after {content: \"\";width: 100%;border-bottom: 1px solid gray;flex-grow: 1;}#sk-container-id-2 div.sk-label:hover label.sk-toggleable__label {background-color: #d4ebff;}#sk-container-id-2 div.sk-serial::before {content: \"\";position: absolute;border-left: 1px solid gray;box-sizing: border-box;top: 0;bottom: 0;left: 50%;z-index: 0;}#sk-container-id-2 div.sk-serial {display: flex;flex-direction: column;align-items: center;background-color: white;padding-right: 0.2em;padding-left: 0.2em;position: relative;}#sk-container-id-2 div.sk-item {position: relative;z-index: 1;}#sk-container-id-2 div.sk-parallel {display: flex;align-items: stretch;justify-content: center;background-color: white;position: relative;}#sk-container-id-2 div.sk-item::before, #sk-container-id-2 div.sk-parallel-item::before {content: \"\";position: absolute;border-left: 1px solid gray;box-sizing: border-box;top: 0;bottom: 0;left: 50%;z-index: -1;}#sk-container-id-2 div.sk-parallel-item {display: flex;flex-direction: column;z-index: 1;position: relative;background-color: white;}#sk-container-id-2 div.sk-parallel-item:first-child::after {align-self: flex-end;width: 50%;}#sk-container-id-2 div.sk-parallel-item:last-child::after {align-self: flex-start;width: 50%;}#sk-container-id-2 div.sk-parallel-item:only-child::after {width: 0;}#sk-container-id-2 div.sk-dashed-wrapped {border: 1px dashed gray;margin: 0 0.4em 0.5em 0.4em;box-sizing: border-box;padding-bottom: 0.4em;background-color: white;}#sk-container-id-2 div.sk-label label {font-family: monospace;font-weight: bold;display: inline-block;line-height: 1.2em;}#sk-container-id-2 div.sk-label-container {text-align: center;}#sk-container-id-2 div.sk-container {/* jupyter's `normalize.less` sets `[hidden] { display: none; }` but bootstrap.min.css set `[hidden] { display: none !important; }` so we also need the `!important` here to be able to override the default hidden behavior on the sphinx rendered scikit-learn.org. See: https://github.com/scikit-learn/scikit-learn/issues/21755 */display: inline-block !important;position: relative;}#sk-container-id-2 div.sk-text-repr-fallback {display: none;}</style><div id=\"sk-container-id-2\" class=\"sk-top-container\"><div class=\"sk-text-repr-fallback\"><pre>LogisticRegression(random_state=0)</pre><b>In a Jupyter environment, please rerun this cell to show the HTML representation or trust the notebook. <br />On GitHub, the HTML representation is unable to render, please try loading this page with nbviewer.org.</b></div><div class=\"sk-container\" hidden><div class=\"sk-item\"><div class=\"sk-estimator sk-toggleable\"><input class=\"sk-toggleable__control sk-hidden--visually\" id=\"sk-estimator-id-2\" type=\"checkbox\" checked><label for=\"sk-estimator-id-2\" class=\"sk-toggleable__label sk-toggleable__label-arrow\">LogisticRegression</label><div class=\"sk-toggleable__content\"><pre>LogisticRegression(random_state=0)</pre></div></div></div></div></div>"
      ],
      "text/plain": [
       "LogisticRegression(random_state=0)"
      ]
     },
     "execution_count": 25,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "from sklearn.linear_model import LogisticRegression\n",
    "\n",
    "log = LogisticRegression(random_state = 0)\n",
    "log.fit(X_train, Y_train)"
   ]
  },
  {
   "cell_type": "raw",
   "id": "a4f09ae2-d9dd-41c1-955f-3b377fe43160",
   "metadata": {},
   "source": [
    "MODEL PREDICTION"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 26,
   "id": "58639165-2cac-49e1-b21d-ffdf70705689",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[0 0 1 0 1 0 1 0 0 0 1 1 0 0 0 0 1 0 1 1 0 1 0 0 0 0 1 0 0 0 1 1 1 1 1 0 0\n",
      " 1 1 1 1 0 1 1 0 1 0 0 0 0 0 1 1 0 0 1 0 1 0 0 0 1 1 0 0 1 1 1 1 0 0 1 1 1\n",
      " 1 0 0 1 0 1 0 1 0 0]\n"
     ]
    }
   ],
   "source": [
    "pred = print(log.predict(X_test))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 27,
   "id": "ce375588-a4ea-4fef-b6f4-9a54c1ebfbcc",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "360    0\n",
      "170    0\n",
      "224    1\n",
      "358    0\n",
      "309    1\n",
      "      ..\n",
      "100    1\n",
      "7      0\n",
      "22     1\n",
      "68     0\n",
      "328    0\n",
      "Name: Survived, Length: 84, dtype: int64\n"
     ]
    }
   ],
   "source": [
    "print(Y_test)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 28,
   "id": "f82377d1-f4c0-4c94-8dcd-c658e147e0bd",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "So Sorry! Not Survived\n"
     ]
    }
   ],
   "source": [
    "import warnings\n",
    "warnings.filterwarnings(\"ignore\")\n",
    "\n",
    "res= log.predict([[2,1]])\n",
    "\n",
    "if(res==0):\n",
    "  print(\"Not Survived\")\n",
    "else:\n",
    "  print(\"Survived\")"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "5a18e326-1534-4b78-9c84-75570cce2efe",
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3 (ipykernel)",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.10.8"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 5
}