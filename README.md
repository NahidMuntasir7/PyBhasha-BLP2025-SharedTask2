# PyBhasha at BLP-2025 Task 2: Effectiveness of Semantic-Aware Translation and Ensembling in Bangla Code Generation

This repository contains the official implementation of our submission to **Task 2** of the **Bangla Language Processing (BLP-2025) Shared Task on Bangla-to-Python Code Generation**.  
Our system, **PyBhasha**, investigates how the *semantic quality of translated instructions* and a *two-stage ensemble strategy* influence code-generation performance.

---

## 🧠 Overview

Large Language Models (LLMs) such as Codex, CodeLLaMA, and DeepSeek-Coder have demonstrated strong code-generation ability in English, yet performance remains limited for low-resource languages like **Bangla**.  
This work explores how translation quality and instruction formulation affect Bangla-to-Python generation across multiple open-source and proprietary models.

We evaluate three instruction variants:

1. **Original Bangla instructions**  
2. **Facebook NLLB translations** (Bangla → English)  
3. **GPT-4.1 rewritten English instructions**

Our results show that GPT-4.1-based reformulations produce more semantically precise prompts, resulting in consistently higher code-generation accuracy.  
A lightweight **two-stage ensemble** combining Qwen2.5-Coder-14B and Claude Sonnet 4 further improves robustness and achieves our best leaderboard result.

---

## ⚙️ Experimental Setup

All experiments were conducted on **Kaggle P100 GPU (16 GB)** using 4-bit inference via *bitsandbytes* to support large-parameter models efficiently.  
No additional training or fine-tuning was performed — the focus was on **inference-time translation and ensembling**.

### Models Evaluated
- Qwen2.5-Coder-3B / 7B / 14B-Instruct  
- TigerLLM-9B-it  
- Meta-LLaMA-3.1-8B-Instruct  
- Claude Sonnet 4  
- GPT-4.1  

### Instruction Variants
Each model was tested under:
- **Original Bangla**
- **NLLB translation**
- **GPT-4.1 rewriting**

---

## 🧩 Ensemble Strategy

To further enhance performance and minimize failure cases, we adopted a **two-stage ensemble strategy** that combines the strengths of two high-performing models — **Qwen2.5-Coder-14B-Instruct** and **Claude Sonnet 4**.

---

## 📊 Results and Analysis

We evaluated all models on both **development (dev)** and **hidden test sets** under three instruction settings as described in experimental setup (instruction variants).

The metric used was **pass@1** — the proportion of test cases fully solved by the generated code.

| **Model Name** | **Dev (Original)** | **Dev (NLLB)** | **Dev (GPT-4.1)** | **Test (Original)** | **Test (NLLB)** | **Test (GPT-4.1)** |
|:----------------|:------------------:|:---------------:|:-----------------:|:-------------------:|:----------------:|:------------------:|
| TigerLLM-9B-it | 72.5 | 65.5 | 77.3 | 58.6 | 56.8 | 63.6 |
| Qwen2.5-Coder-3B-Instruct | 52.0 | 57.0 | 67.0 | 47.0 | 48.4 | 56.2 |
| Qwen2.5-Coder-7B-Instruct | 62.0 | 66.0 | 73.0 | 59.8 | 64.4 | 69.2 |
| Qwen2.5-Coder-14B-Instruct | 77.0 | 76.0 | 82.0 | 67.2 | 68.2 | 76.0 |
| Meta-LLaMA-3.1-8B-Instruct | 48.0 | 50.0 | 56.0 | 45.6 | 47.2 | 52.0 |
| Claude Sonnet 4 | – | – | 82.0 | – | – | 72.4 |
| GPT-4.1 | – | – | 77.8 | – | – | 71.0 |
| **Two-Stage Ensemble**<br/>(Qwen 14B + Claude 4) | – | – | – | – | – | **80.0** |

**Key Observations:**
- GPT-4.1-based English rewrites consistently yielded the best accuracy across all models.  
- Qwen2.5-Coder-14B-Instruct emerged as the strongest open-source baseline.  
- The two-stage ensemble surpassed both standalone models, achieving **80.0 % pass@1** on the hidden test set and placing **12th on the official leaderboard**.  
- NLLB translations introduced semantic drift in complex mathematical or geometric problems, while GPT-4.1 rewrites maintained conceptual precision.

---

## 🧠 Insights

- **Instruction formulation strongly affects code quality** — clearer semantics lead to better logical alignment during generation.  
- **Translation quality is critical:** GPT-4.1 preserved task intent better than NLLB, especially for domain-specific terms (e.g., geometry, bitwise operations).  
- **Simple ensembling works:** The fallback pipeline provided measurable accuracy gains without additional compute or fine-tuning.

---

## 🏁 Summary

Our approach demonstrated that:
- Semantically precise English reformulations can substantially improve Bangla code generation.  
- A lightweight two-model ensemble further enhances robustness and accuracy.  
- Even without fine-tuning, translation-aware prompting and strategic model combination can reach competitive leaderboard performance.

Final submission: **pass@1 = 80.0 % (12th Place, BLP-2025 Task 2)**
